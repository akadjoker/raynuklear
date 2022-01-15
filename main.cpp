#include <iostream>
#include <raylib.h>
#include <rlgl.h>
#include "src/glue.h"


#include "box2d/box2d.h"


using namespace std;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

const int PIXELRATIO=30;

#define	PI	3.1415926	/* ratio of circumference to diameter */
#define EPSILON	0.000001	/* a quantity small enough to be zero */
#define MAXPOLY		200

struct Polygon
{
   Vector2 p[MAXPOLY];
   int n;

};
struct Triangulation
{
		int n;
		int t[MAXPOLY][3];
};

struct Triangle
{
    Vector2 a, b, c;
};
double signed_triangle_area(Vector2 a, Vector2 b, Vector2 c)
{
    return ((a.x*b.y-a.y*b.x+a.y*c.x-a.x*c.y+b.x*c.y-c.x*b.y)/2.0f);
}

 bool cw(Vector2 a, Vector2 b, Vector2 c)
{
    return signed_triangle_area(a,b,c) < -EPSILON;
}

 bool point_in_triangle(Vector2 p, Triangle t)
{
    if(cw(t.a,t.b,p)) return false;
    if(cw(t.b,t.c,p)) return false;
    if(cw(t.c,t.a,p)) return false;
    return true;
}

bool ear_Q(int i, int j, int k, Polygon p)
	{
     	Triangle t;
		t.a = p.p[i];
		t.b = p.p[j];
		t.c = p.p[k];

		if(cw(t.a,t.b,t.c)) return false;

		for(int m=0;m<p.n;m++)
			if(m!=i&&m!=j&&m!=k)
				if(point_in_triangle(p.p[m],t))
					return false;

		return true;
	}

 double triangle_area(Vector2 a, Vector2 b, Vector2 c)
{
    return fabs(signed_triangle_area(a,b,c));
}

Triangulation Triangulate(Polygon p)
	{
		int l[MAXPOLY] ;
		int r[MAXPOLY] ;
		for(int i=0;i<p.n;i++)
		{
			l[i] = (i-1+p.n)%p.n;
			r[i] = (i+1+p.n)%p.n;
		}
		Triangulation t;
		t.n = 0;
		int i = p.n-1;
		while(t.n < p.n - 2)
		{
			i = r[i];
			if(ear_Q(l[i],i,r[i],p))
			{
				t.t[t.n][0] = l[i];
				t.t[t.n][1] = i;
				t.t[t.n][2] = r[i];
				t.n++;
				l[r[i]] = l[i];
				r[l[i]] = r[i];
			}
		}
		return t;
	}

 double area_triangulation(Polygon p)
{
    Triangulation t;
    double total = 0;
    t = Triangulate(p);
    for(int i=0;i<t.n;i++)
        total+=triangle_area(p.p[t.t[i][0]],p.p[t.t[i][1]],p.p[t.t[i][2]]);
    return total;
}

 double area(Polygon p)
{
    double total = 0;
    for(int i=0;i<p.n;i++)
    {
        int j = (i+1)%p.n;
        total += (p.p[i].x*p.p[j].y) - (p.p[j].x*p.p[i].y);
    }
    return total / 2;
}


void rDrawCircle(float x,float y, float r,Color c)
{
DrawCircle(x,y,r,c);
}

class B2D_DebugDraw : public b2Draw{
 public:
  B2D_DebugDraw()
  {


        AppendFlags(b2Draw::e_shapeBit);
        AppendFlags(b2Draw::e_jointBit);
      //  AppendFlags(b2Draw::e_aabbBit);
       // AppendFlags(b2Draw::e_pairBit);
        AppendFlags(b2Draw::e_centerOfMassBit);

  };
 void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color &c)
    {

      rlBegin(RL_LINES);
                   Color color;
                   color.r=c.r*255;
                   color.g=c.g*255;
                   color.b=c.b*255;
                   color.a=c.a*255;
                      b2Vec2 p1 = vertices[vertexCount - 1];
                      for (int i = 0; i < vertexCount; ++i)
                      {
                        b2Vec2 p2 = vertices[i];
                        rlColor4ub(color.r, color.g, color.b, color.a);
                        rlVertex2f(p1.x*PIXELRATIO,p1.y*PIXELRATIO);
                        rlVertex2f(p2.x*PIXELRATIO,p2.y*PIXELRATIO);
                        p1 = p2;
                      }
        rlEnd();

    }

    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color &c)
    {

     rlBegin(RL_TRIANGLES);
                   Color color;
                   color.r=c.r*255;
                   color.g=c.g*255;
                   color.b=c.b*255;
                   color.a=c.a*155;

                      b2Vec2 p3 = vertices[0];
                      for (int i = 1; i < vertexCount-1; i++)
                      {

                        b2Vec2 p1 = vertices[i+1];
                        b2Vec2 p2 = vertices[i];
                        b2Vec2 p3 = vertices[0];
                        rlColor4ub(color.r, color.g, color.b, color.a);
                        rlVertex2f(p1.x*PIXELRATIO,p1.y*PIXELRATIO);
                        rlVertex2f(p2.x*PIXELRATIO,p2.y*PIXELRATIO);
                        rlVertex2f(p3.x*PIXELRATIO,p3.y*PIXELRATIO);

                      }
        rlEnd();


    }

    void DrawCircle(const b2Vec2& p, float radius, const b2Color &c)
    {
              Color color;
                   color.r=c.r*255;
                   color.g=c.g*255;
                   color.b=c.b*255;
                   color.a=c.a*255;


        DrawCircleLines(p.x*PIXELRATIO, p.y*PIXELRATIO, radius*PIXELRATIO, color);
    }

    void DrawSolidCircle(const b2Vec2& p, float radius, const b2Vec2&, const b2Color &c) {
//        std::cout << "DrawSolidCircle" << "x" << center.x << "y" << center.y << "radius" << radius;
        Color color;
                   color.r=c.r*255;
                   color.g=c.g*255;
                   color.b=c.b*255;
                   color.a=c.a*255;

        //std::cout << "DrawCircle" << "x" << center.x << "y" << center.y << "radius" << radius;
        rDrawCircle(p.x*PIXELRATIO, p.y*PIXELRATIO, radius*PIXELRATIO, color);
    }

    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color &c) {
        //std::cout << "DrawSegment" << "p1.x" << p1.x << "p1.y" << p1.y << "p2.x" << p2.x << "p2.y" << p2.y;
                   Color color;
                   color.r=c.r*255;
                   color.g=c.g*255;
                   color.b=c.b*255;
                   color.a=c.a*255;

          DrawLine(p1.x*PIXELRATIO, p1.y*PIXELRATIO, p2.x*PIXELRATIO, p2.y*PIXELRATIO, color);
    }

    void DrawTransform(const b2Transform& xf) {
   //     std::cout << "DrawTransform" << "x" << xf.p.x << "y" << xf.p.y << "angle" << xf.q.GetAngle();
    }
    void DrawPoint(const b2Vec2 &p, float size, const b2Color &c)
    {
              Color color;
                   color.r=c.r*255;
                   color.g=c.g*255;
                   color.b=c.b*255;
                   color.a=c.a*255;

       rDrawCircle(p.x*PIXELRATIO, p.y*PIXELRATIO, size*PIXELRATIO, color);
    }
};




///**************************************************************************************
float TriangulateArea(const Vector2* contour,int n)
{



  float A=0.0f;

  for(int p=n-1,q=0; q<n; p=q++)
  {
    A+= contour[p].x*contour[q].y - contour[q].x*contour[p].y;
  }
  return A*0.5f;
}

bool InsideTriangle(float Ax, float Ay,
                      float Bx, float By,
                      float Cx, float Cy,
                      float Px, float Py)
{
  float ax, ay, bx, by, cx, cy, apx, apy, bpx, bpy, cpx, cpy;
  float cCROSSap, bCROSScp, aCROSSbp;

  ax = Cx - Bx;  ay = Cy - By;
  bx = Ax - Cx;  by = Ay - Cy;
  cx = Bx - Ax;  cy = By - Ay;
  apx= Px - Ax;  apy= Py - Ay;
  bpx= Px - Bx;  bpy= Py - By;
  cpx= Px - Cx;  cpy= Py - Cy;

  aCROSSbp = ax*bpy - ay*bpx;
  cCROSSap = cx*apy - cy*apx;
  bCROSScp = bx*cpy - by*cpx;

  return ((aCROSSbp >= 0.0f) && (bCROSScp >= 0.0f) && (cCROSSap >= 0.0f));
}


bool Snip(const  Vector2* contour,int u,int v,int w,int n,int *V)
{
  int p;
  float Ax, Ay, Bx, By, Cx, Cy, Px, Py;

  Ax = contour[V[u]].x;
  Ay = contour[V[u]].y;

  Bx = contour[V[v]].x;
  By = contour[V[v]].y;

  Cx = contour[V[w]].x;
  Cy = contour[V[w]].y;

  if ( EPSILON > (((Bx-Ax)*(Cy-Ay)) - ((By-Ay)*(Cx-Ax))) ) return false;

  for (p=0;p<n;p++)
  {
    if( (p == u) || (p == v) || (p == w) ) continue;
    Px = contour[V[p]].x;
    Py = contour[V[p]].y;
    if (InsideTriangle(Ax,Ay,Bx,By,Cx,Cy,Px,Py)) return false;
  }

  return true;
}
int smeTriangulate(const Vector2* contour,int n,Vector2* result)
{
  /* allocate and initialize list of Vertices in polygon */


  if ( n < 3 )
  {
   printf("** Triangulate: ERROR - %d < 3!\n",n);
   return 0;
  }

  int *V = new int[n];

int total=0;


  /* we want a counter-clockwise polygon in V */

  if ( 0.0f < TriangulateArea(contour,n) )
    for (int v=0; v<n; v++) V[v] = v;
  else
    for(int v=0; v<n; v++) V[v] = (n-1)-v;

  int nv = n;

  /*  remove nv-2 Vertices, creating 1 triangle every time */
  int count = 2*nv;   /* error detection */

  for(int m=0, v=nv-1; nv>2; )
  {
    /* if we loop, it is probably a non-simple polygon */
    if (0 >= (count--))
    {
      printf("** Triangulate: ERROR - probable bad polygon!\n");
      return 0;
    }

    /* three consecutive vertices in current polygon, <u,v,w> */
    int u = v  ; if (nv <= u) u = 0;     /* previous */
    v = u+1; if (nv <= v) v = 0;     /* new v    */
    int w = v+1; if (nv <= w) w = 0;     /* next     */

    if ( Snip(contour,u,v,w,nv,V) )
    {
      int a,b,c,s,t;

      /* true names of the vertices */
      a = V[u]; b = V[v]; c = V[w];

      /* output Triangle */
      result[total++]=contour[a] ;
      result[total++]=contour[b] ;
      result[total++]=contour[c] ;

      m++;

      /* remove v from remaining polygon */
      for(s=v,t=v+1;t<nv;s++,t++) V[s] = V[t]; nv--;

      /* resest error detection counter */
      count = 2*nv;
    }
  }



  delete V;

  return total;
}


b2World* world;




void static_box(float w, float h, float x,float y)
{
b2BodyDef groundBodyDef;
groundBodyDef.position.Set(x/PIXELRATIO, y/PIXELRATIO);
b2Body* groundBody = world->CreateBody(&groundBodyDef);
b2PolygonShape groundBox;
groundBox.SetAsBox(w/PIXELRATIO, h/PIXELRATIO);
groundBody->CreateFixture(&groundBox, 0.0f);
}



void bodybox(float w, float h, float x,float y)
{
b2BodyDef bodyDef;
bodyDef.type = b2_dynamicBody;
bodyDef.position.Set(x/PIXELRATIO, y/PIXELRATIO);

b2Body* body = world->CreateBody(&bodyDef);


b2PolygonShape dynamicBox;
dynamicBox.SetAsBox(w/PIXELRATIO, h/PIXELRATIO);

b2FixtureDef fixtureDef;
fixtureDef.shape = &dynamicBox;
fixtureDef.density = 0.1f;
fixtureDef.friction = 0.3f;
fixtureDef.restitution=0.1f;
body->CreateFixture(&fixtureDef);

}

void bodycircle(float r, float x,float y)
{
b2BodyDef bodyDef;
bodyDef.type = b2_dynamicBody;
bodyDef.position.Set(x/PIXELRATIO, y/PIXELRATIO);
b2Body* body = world->CreateBody(&bodyDef);
b2CircleShape dynamicCircle;

//dynamicCircle.m_p.Set(x/PIXELRATIO,y/PIXELRATIO);
dynamicCircle.m_radius=r/PIXELRATIO;


b2FixtureDef fixtureDef;
fixtureDef.shape = &dynamicCircle;
fixtureDef.density = 0.1f;
fixtureDef.friction = 0.3f;
fixtureDef.restitution=0.1f;
body->CreateFixture(&fixtureDef);
}

int main(void)
{
    // Initialization

    //--------------------------------------------------------------------------------------
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [nuklear] example");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    /* GUI */
    struct nk_context *ctx;
    struct nk_colorf bg;
    ctx = nk_raylib_init();

    int NUM_VERTS =400;
    int NUM_TRIS=0;
    int count=0;
    Polygon points;
    Vector2 tris[NUM_VERTS];
    double TwoPi =6.2831853071795862;
    float radius=50;

    for (int i=0;i<NUM_VERTS;i++)
    {
    float angle = TwoPi * i / NUM_VERTS;
    //points[i].x=radius*cos( angle );
    //points[i].y=radius*sin( angle );

    }


b2Vec2 gravity(0.0f, 10.0f);

 world= new b2World(gravity);

float time_step = 1.0f / 60.0f;
int32 velocity_itePIXELRATIOns = 6;
int32 position_itePIXELRATIOns = 2;
B2D_DebugDraw debug_draw;

world->SetDebugDraw(&debug_draw);


static_box(500,5,WINDOW_WIDTH/2,WINDOW_HEIGHT-50);
static_box(10,WINDOW_HEIGHT/2-20,100,WINDOW_HEIGHT/2);
static_box(10,WINDOW_HEIGHT/2-20,WINDOW_WIDTH-100,WINDOW_HEIGHT/2);

bool working=false;

Triangulation tri;

bodybox(10,10,300,100);
bodybox(10,10,300,40);
bodybox(10,10,300,1);
bodycircle(15,300,100);
points.p[count].x=100;
points.p[count].y=100;
count++;

points.p[count].x=100;
points.p[count].y=200;
count++;

points.p[count].x=200;
points.p[count].y=200;
count++;

points.p[count].x=200;
points.p[count].y=100;
count++;

points.p[count].x=150;
points.p[count].y=50;

points.n=count-1;
count++;




    // Main game loop
    bg.r = 0.10f, bg.g = 0.18f, bg.b = 0.24f, bg.a = 1.0f;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        nk_raylib_input(ctx);

        /* GUI */
        if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
            NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
            NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
        {
            enum {EASY, HARD};
            static int op = EASY;
            static int property = 20;
            nk_layout_row_static(ctx, 30, 80, 1);
            if (nk_button_label(ctx, "Box"))
            {


points.p[count].x=100;
points.p[count].y=100;
count++;

points.p[count].x=100;
points.p[count].y=200;
count++;

points.p[count].x=200;
points.p[count].y=200;
count++;

points.p[count].x=200;
points.p[count].y=100;
count++;

points.p[count].x=150;
points.p[count].y=50;
count++;

points.n=count-1;
}


             if (nk_button_label(ctx, "Circle"))
            {
                working=false;

             }

               if (nk_button_label(ctx, "Reset"))
            {
                count=0;

             }

                 if (nk_button_label(ctx, "Build"))
            {


               working=true;



               printf(" area via triangulation = %f\n", area_triangulation(points));
		        printf(" area slick = %f\n", area(points));
		        printf(" area num = %d\n",tri.n);


             //  printf(" %d \n",NUM_TRIS);

             }
            nk_layout_row_dynamic(ctx, 30, 2);
            if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
            if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;

            nk_layout_row_dynamic(ctx, 25, 1);
            nk_property_int(ctx, "Compression:", 0, &NUM_TRIS, 100, 10, 1);

            nk_layout_row_dynamic(ctx, 20, 1);
            nk_label(ctx, "background:", NK_TEXT_LEFT);
            nk_layout_row_dynamic(ctx, 25, 1);
            if (nk_combo_begin_color(ctx, nk_rgb_cf(bg), nk_vec2(nk_widget_width(ctx),400))) {
                nk_layout_row_dynamic(ctx, 120, 1);
                bg = nk_color_picker(ctx, bg, NK_RGBA);
                nk_layout_row_dynamic(ctx, 25, 1);
                bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
                bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
                bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
                bg.a = nk_propertyf(ctx, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
                nk_combo_end(ctx);
            }
        }
        nk_end(ctx);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(nk_colorf_to_raylib_color(bg));

            nk_raylib_render(ctx);

        rlPushMatrix();
      //   rlTranslatef(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0.0f);
         rlTranslatef(0,0,0);
         //DrawTriangleFan(points,NUM_VERTS, RED);

       // DrawTriangleStrip(points,NUM_VERTS, RED);

        //DrawTriangle(points[0],points[1],points[2],LIME);




                   for (int j = 0; j < count; j++)
                    {
                        Vector2 vertexA;
                        Vector2 vertexB;
                        vertexA.x=points.p[j].x;
                        vertexA.y=points.p[j].y;
                        int jj = (((j + 1) < count) ? (j + 1) : 0);   // Get next vertex or first to close the shape
                        vertexB.x=points.p[jj].x;
                        vertexB.y=points.p[jj].y;
                        DrawLineV(vertexA, vertexB, BLUE);     // Draw a line between two vertex positions
                    }

/*
                   //rlBegin(RL_QUADS);
                   rlBegin(RL_TRIANGLES);
                   Color color=LIME;

                      for (int i = 1; i < count-1 ; i++)
                        {
                       // rlColor4ub(color.r, color.g, color.b, color.a);
                      //  rlVertex2f(points[i+1].x,points[i+1].y);
                       // rlVertex2f(points[i].x,points[i].y);
                        //rlVertex2f(points[0].x,points[0].y);

                        rlColor4ub(color.r, color.g, color.b, color.a);
                        rlVertex2f(points[0].x,points[0].y);
                        rlVertex2f(points[i].x,points[i].y);
                        rlVertex2f(points[i+1].x,points[i+1].y);
                        }
                    rlEnd();
*/
/*
                    rlBegin(RL_LINES);
                    color=RED;
                   rlColor4ub(color.r, color.g, color.b, color.a);
                      for (int i = 1; i < count-1 ; i++)
                        {
                        rlVertex2f(points[i+1].x,points[i+1].y);
                        rlVertex2f(points[i].x,points[i].y);
                        rlVertex2f(points[0].x,points[0].y);
                        }
                    rlEnd();
*/
                    if (IsMouseButtonDown(1))
                    {
                     points.p[count].x=GetMouseX();
                     points.p[count].y=GetMouseY();
                    // points.n=count;
                     count++;
                    }




          for (int i=0;i<count;i++)
          {
          DrawCircleLines(points.p[i].x,points.p[i].y,2,WHITE);

          }

           for (int i=0;i<NUM_TRIS;i++)
          {
          DrawCircleLines(tris[i].x,tris[i].y,2,BLUE);

          }

             rlBegin(RL_TRIANGLES);
                   Color color=LIME;

                      for (int i = 1; i < NUM_TRIS-1 ; i++)
                        {
                        rlColor4ub(color.r, color.g, color.b, color.a);
                        rlVertex2f(tris[i+1].x,tris[i+1].y);
                        rlVertex2f(tris[i].x,tris[i].y);
                        rlVertex2f(tris[0].x,tris[0].y);


                        }
                    rlEnd();

        // DrawCircle(0,0,20,RED);


        // world->Step(time_step, velocity_itePIXELRATIOns, position_itePIXELRATIOns);
//for (int i = 0; i < 60; ++i)
{
    world->Step(time_step, velocity_itePIXELRATIOns, position_itePIXELRATIOns);
//    b2Vec2 position = body->GetPosition();
 //   float angle = body->GetAngle();
  //  printf("%4.2f %4.2f %4.2f\n", position.x*pmPIXELRATIO, position.y*pmPIXELRATIO, angle);
  //  DrawCircle( position.x*PIXELRATIO, position.y*PIXELRATIO,5,RED);
    world->DebugDraw();

}
        rlPopMatrix();




        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
   delete world;
    nk_raylib_free(ctx);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
