#include "glue.h"
#define NK_IMPLEMENTATION
#include "nuklear.h"

enum theme {THEME_BLACK, THEME_WHITE, THEME_RED, THEME_BLUE, THEME_DARK};

static void nk_set_style(struct nk_context *ctx, enum theme theme)
{
    struct nk_color table[NK_COLOR_COUNT];
    if (theme == THEME_WHITE) {
        table[NK_COLOR_TEXT] = nk_rgba(70, 70, 70, 255);
        table[NK_COLOR_WINDOW] = nk_rgba(175, 175, 175, 255);
        table[NK_COLOR_HEADER] = nk_rgba(175, 175, 175, 255);
        table[NK_COLOR_BORDER] = nk_rgba(0, 0, 0, 255);
        table[NK_COLOR_BUTTON] = nk_rgba(185, 185, 185, 255);
        table[NK_COLOR_BUTTON_HOVER] = nk_rgba(170, 170, 170, 255);
        table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(160, 160, 160, 255);
        table[NK_COLOR_TOGGLE] = nk_rgba(150, 150, 150, 255);
        table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(120, 120, 120, 255);
        table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(175, 175, 175, 255);
        table[NK_COLOR_SELECT] = nk_rgba(190, 190, 190, 255);
        table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(175, 175, 175, 255);
        table[NK_COLOR_SLIDER] = nk_rgba(190, 190, 190, 255);
        table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(80, 80, 80, 255);
        table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(70, 70, 70, 255);
        table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(60, 60, 60, 255);
        table[NK_COLOR_PROPERTY] = nk_rgba(175, 175, 175, 255);
        table[NK_COLOR_EDIT] = nk_rgba(150, 150, 150, 255);
        table[NK_COLOR_EDIT_CURSOR] = nk_rgba(0, 0, 0, 255);
        table[NK_COLOR_COMBO] = nk_rgba(175, 175, 175, 255);
        table[NK_COLOR_CHART] = nk_rgba(160, 160, 160, 255);
        table[NK_COLOR_CHART_COLOR] = nk_rgba(45, 45, 45, 255);
        table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
        table[NK_COLOR_SCROLLBAR] = nk_rgba(180, 180, 180, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(140, 140, 140, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(150, 150, 150, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(160, 160, 160, 255);
        table[NK_COLOR_TAB_HEADER] = nk_rgba(180, 180, 180, 255);
        nk_style_from_table(ctx, table);
    } else if (theme == THEME_RED) {
        table[NK_COLOR_TEXT] = nk_rgba(190, 190, 190, 255);
        table[NK_COLOR_WINDOW] = nk_rgba(30, 33, 40, 215);
        table[NK_COLOR_HEADER] = nk_rgba(181, 45, 69, 220);
        table[NK_COLOR_BORDER] = nk_rgba(51, 55, 67, 255);
        table[NK_COLOR_BUTTON] = nk_rgba(181, 45, 69, 255);
        table[NK_COLOR_BUTTON_HOVER] = nk_rgba(190, 50, 70, 255);
        table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(195, 55, 75, 255);
        table[NK_COLOR_TOGGLE] = nk_rgba(51, 55, 67, 255);
        table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(45, 60, 60, 255);
        table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(181, 45, 69, 255);
        table[NK_COLOR_SELECT] = nk_rgba(51, 55, 67, 255);
        table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(181, 45, 69, 255);
        table[NK_COLOR_SLIDER] = nk_rgba(51, 55, 67, 255);
        table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(181, 45, 69, 255);
        table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(186, 50, 74, 255);
        table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(191, 55, 79, 255);
        table[NK_COLOR_PROPERTY] = nk_rgba(51, 55, 67, 255);
        table[NK_COLOR_EDIT] = nk_rgba(51, 55, 67, 225);
        table[NK_COLOR_EDIT_CURSOR] = nk_rgba(190, 190, 190, 255);
        table[NK_COLOR_COMBO] = nk_rgba(51, 55, 67, 255);
        table[NK_COLOR_CHART] = nk_rgba(51, 55, 67, 255);
        table[NK_COLOR_CHART_COLOR] = nk_rgba(170, 40, 60, 255);
        table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
        table[NK_COLOR_SCROLLBAR] = nk_rgba(30, 33, 40, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(64, 84, 95, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(70, 90, 100, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(75, 95, 105, 255);
        table[NK_COLOR_TAB_HEADER] = nk_rgba(181, 45, 69, 220);
        nk_style_from_table(ctx, table);
    } else if (theme == THEME_BLUE) {
        table[NK_COLOR_TEXT] = nk_rgba(20, 20, 20, 255);
        table[NK_COLOR_WINDOW] = nk_rgba(202, 212, 214, 215);
        table[NK_COLOR_HEADER] = nk_rgba(137, 182, 224, 220);
        table[NK_COLOR_BORDER] = nk_rgba(140, 159, 173, 255);
        table[NK_COLOR_BUTTON] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_BUTTON_HOVER] = nk_rgba(142, 187, 229, 255);
        table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(147, 192, 234, 255);
        table[NK_COLOR_TOGGLE] = nk_rgba(177, 210, 210, 255);
        table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(182, 215, 215, 255);
        table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_SELECT] = nk_rgba(177, 210, 210, 255);
        table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_SLIDER] = nk_rgba(177, 210, 210, 255);
        table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(137, 182, 224, 245);
        table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(142, 188, 229, 255);
        table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(147, 193, 234, 255);
        table[NK_COLOR_PROPERTY] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_EDIT] = nk_rgba(210, 210, 210, 225);
        table[NK_COLOR_EDIT_CURSOR] = nk_rgba(20, 20, 20, 255);
        table[NK_COLOR_COMBO] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_CHART] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_CHART_COLOR] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
        table[NK_COLOR_SCROLLBAR] = nk_rgba(190, 200, 200, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(64, 84, 95, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(70, 90, 100, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(75, 95, 105, 255);
        table[NK_COLOR_TAB_HEADER] = nk_rgba(156, 193, 220, 255);
        nk_style_from_table(ctx, table);
    } else if (theme == THEME_DARK) {
        table[NK_COLOR_TEXT] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_WINDOW] = nk_rgba(57, 67, 71, 215);
        table[NK_COLOR_HEADER] = nk_rgba(51, 51, 56, 220);
        table[NK_COLOR_BORDER] = nk_rgba(46, 46, 46, 255);
        table[NK_COLOR_BUTTON] = nk_rgba(48, 83, 111, 255);
        table[NK_COLOR_BUTTON_HOVER] = nk_rgba(58, 93, 121, 255);
        table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(63, 98, 126, 255);
        table[NK_COLOR_TOGGLE] = nk_rgba(50, 58, 61, 255);
        table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(45, 53, 56, 255);
        table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(48, 83, 111, 255);
        table[NK_COLOR_SELECT] = nk_rgba(57, 67, 61, 255);
        table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(48, 83, 111, 255);
        table[NK_COLOR_SLIDER] = nk_rgba(50, 58, 61, 255);
        table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(48, 83, 111, 245);
        table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(53, 88, 116, 255);
        table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(58, 93, 121, 255);
        table[NK_COLOR_PROPERTY] = nk_rgba(50, 58, 61, 255);
        table[NK_COLOR_EDIT] = nk_rgba(50, 58, 61, 225);
        table[NK_COLOR_EDIT_CURSOR] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_COMBO] = nk_rgba(50, 58, 61, 255);
        table[NK_COLOR_CHART] = nk_rgba(50, 58, 61, 255);
        table[NK_COLOR_CHART_COLOR] = nk_rgba(48, 83, 111, 255);
        table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba(255, 0, 0, 255);
        table[NK_COLOR_SCROLLBAR] = nk_rgba(50, 58, 61, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(48, 83, 111, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(53, 88, 116, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(58, 93, 121, 255);
        table[NK_COLOR_TAB_HEADER] = nk_rgba(48, 83, 111, 255);
        nk_style_from_table(ctx, table);
    } else {
        nk_style_default(ctx);
    }
}



NK_API float
nk_raylib_font_get_text_width(nk_handle handle, float height, const char *text, int len)
{
    if (TextLength(text) == 0) {
        return 0;
    }

    struct nk_user_font* userFont = (struct nk_user_font*)handle.ptr;
    if (userFont == NULL) {
        return 0;
    }

    return MeasureText(text, 10);
}

NK_API void
nk_raylib_clipboard_paste(nk_handle usr, struct nk_text_edit *edit)
{
    const char *text = GetClipboardText();
    if (text != NULL) {
        nk_textedit_paste(edit, text, TextLength(text));
    }
    (void)usr;
}

NK_API void
nk_raylib_clipboard_copy(nk_handle usr, const char *text, int len) {
    SetClipboardText(text);
}

NK_API struct nk_context*
nk_raylib_init()
{
    struct nk_context* ctx = (struct nk_context*) calloc(1, sizeof(struct nk_context));

    // Initialize the default font.
    struct Font* font = (struct Font*) calloc(1, sizeof(struct Font));
    struct nk_user_font* userFont = (struct nk_user_font*) calloc(1, sizeof(struct nk_user_font));
    userFont->userdata = nk_handle_ptr(font);
    userFont->height = 10;
    userFont->width = nk_raylib_font_get_text_width;

    // Create the nuklear environment.
    if (nk_init_default(ctx, userFont) == 0) {
        TraceLog(LOG_ERROR, "NUKLEAR: Failed to initialize nuklear.");
        return NULL;
    }

    //enum theme {THEME_BLACK, THEME_WHITE, THEME_RED, THEME_BLUE, THEME_DARK};
    nk_set_style(ctx,THEME_BLACK);

    // Clipboard
    ctx->clip.copy = nk_raylib_clipboard_copy;
    ctx->clip.paste = nk_raylib_clipboard_paste;
    ctx->clip.userdata = nk_handle_ptr(0);

    return ctx;
}

NK_API Color
nk_color_to_raylib_color(struct nk_color color)
{
    Color rc;
    rc.a = color.a;
    rc.r = color.r;
    rc.g = color.g;
    rc.b = color.b;
    return rc;
}

NK_API Color
nk_colorf_to_raylib_color(struct nk_colorf color)
{
    return nk_color_to_raylib_color(nk_rgba_cf(color));
}

NK_API void
nk_raylib_render(struct nk_context * ctx)
{
    const struct nk_command *cmd;
    bool scissor_mode = false;

    nk_foreach(cmd, ctx) {
        Color color;
        switch (cmd->type) {
            case NK_COMMAND_NOP: {
                break;
            }

            case NK_COMMAND_SCISSOR: {
                // TODO: Verify if NK_COMMAND_SCISSOR works.
                const struct nk_command_scissor *s =(const struct nk_command_scissor*)cmd;
                BeginScissorMode(s->x, s->y, s->w, s->h);
                scissor_mode = true;
            } break;

            case NK_COMMAND_LINE: {
                const struct nk_command_line *l = (const struct nk_command_line *)cmd;
                color = nk_color_to_raylib_color(l->color);
                Vector2 startPos = (Vector2){l->begin.x, l->begin.y};
                Vector2 endPos = (Vector2){l->end.x, l->end.y};

                DrawLineEx(startPos, endPos, l->line_thickness, color);
            } break;

            case NK_COMMAND_RECT: {
                const struct nk_command_rect *r = (const struct nk_command_rect *)cmd;
                color = nk_color_to_raylib_color(r->color);
                Rectangle rect = (Rectangle){r->x, r->y, r->w, r->h};
                if (r->rounding > 0) {
                    // TODO: Figure our appropriate roundness.
                    float roundness = (float)r->rounding / 20.0f;
                    DrawRectangleRoundedLines(rect, roundness, 1, r->line_thickness, color);
                }
                else {
                    DrawRectangleLinesEx(rect, r->line_thickness, color);
                }
            } break;

            case NK_COMMAND_RECT_FILLED: {
                const struct nk_command_rect_filled *r = (const struct nk_command_rect_filled *)cmd;
                color = nk_color_to_raylib_color(r->color);
                Rectangle rect = (Rectangle){r->x, r->y, r->w, r->h};
                if (r->rounding > 0) {
                    // TODO: Figure our appropriate roundness.
                    float roundness = (float)r->rounding / 20.0f;
                    DrawRectangleRounded(rect, roundness, 1, color);
                }
                else {
                    DrawRectangleRec(rect, color);
                }
            } break;

            case NK_COMMAND_RECT_MULTI_COLOR: {
                const struct nk_command_rect_multi_color* rectangle = (const struct nk_command_rect_multi_color *)cmd;
                    Rectangle position = (Rectangle){rectangle->x, rectangle->y, rectangle->w, rectangle->h};
                    Color left = nk_color_to_raylib_color(rectangle->left);
                    Color top = nk_color_to_raylib_color(rectangle->top);
                    Color bottom = nk_color_to_raylib_color(rectangle->bottom);
                    Color right = nk_color_to_raylib_color(rectangle->right);
                    DrawRectangleGradientEx(position, left, bottom, right, top);
            } break;

            case NK_COMMAND_CIRCLE: {
                const struct nk_command_circle *c = (const struct nk_command_circle *)cmd;
                color = nk_color_to_raylib_color(c->color);
                DrawEllipseLines(c->x + c->w / 2, c->y + c->h / 2, c->w / 2, c->h / 2, color);
            } break;

            case NK_COMMAND_CIRCLE_FILLED: {
                const struct nk_command_circle_filled *c = (const struct nk_command_circle_filled *)cmd;
                color = nk_color_to_raylib_color(c->color);
                DrawEllipse(c->x + c->w / 2, c->y + c->h / 2, c->w / 2, c->h / 2, color);
            } break;

            case NK_COMMAND_TRIANGLE: {
                const struct nk_command_triangle *t = (const struct nk_command_triangle*)cmd;
                color = nk_color_to_raylib_color(t->color);
                DrawTriangleLines((Vector2){t->b.x, t->b.y}, (Vector2){t->a.x, t->a.y}, (Vector2){t->c.x, t->c.y}, color);
            } break;

            case NK_COMMAND_TRIANGLE_FILLED: {
                const struct nk_command_triangle_filled *t = (const struct nk_command_triangle_filled*)cmd;
                color = nk_color_to_raylib_color(t->color);
                // TODO: Fix needing counter-clockwise order?
                DrawTriangle((Vector2){t->b.x, t->b.y}, (Vector2){t->a.x, t->a.y}, (Vector2){t->c.x, t->c.y}, color);
            } break;

            case NK_COMMAND_POLYGON: {
                const struct nk_command_polygon *p = (const struct nk_command_polygon*)cmd;
                color = nk_color_to_raylib_color(p->color);
                Vector2 points[p->point_count];

                for (int i = 0; i < p->point_count; i++) {
                    points[i] = (Vector2){p->points[i].x, p->points[i].y};
                }

                DrawTriangleFan(points, p->point_count, color);
            } break;

            case NK_COMMAND_POLYGON_FILLED: {
                const struct nk_command_polygon_filled *p = (const struct nk_command_polygon_filled*)cmd;
                color = nk_color_to_raylib_color(p->color);
                Vector2 points[p->point_count];

                for (int i = 0; i < p->point_count; i++) {
                    points[i] = (Vector2){p->points[i].x, p->points[i].y};
                }

                DrawTriangleFan(points, p->point_count, color);
            } break;

            case NK_COMMAND_POLYLINE: {
                const struct nk_command_polyline *p = (const struct nk_command_polyline *)cmd;
                color = nk_color_to_raylib_color(p->color);
                int i;
                Vector2 points[p->point_count];
                for (i = 0; i < p->point_count; i++) {
                    points[i] = (Vector2){p->points[i].x, p->points[i].y};
                }
                // TODO: See if Polyline is correct.
                DrawTriangleStrip(points, p->point_count, color);
            } break;

            case NK_COMMAND_TEXT: {
                const struct nk_command_text *text = (const struct nk_command_text*)cmd;
                color = nk_color_to_raylib_color(text->foreground);
                DrawText((const char*)text->string, text->x, text->y, 10, color);
            } break;

            case NK_COMMAND_CURVE: {
                const struct nk_command_curve *q = (const struct nk_command_curve *)cmd;
                color = nk_color_to_raylib_color(q->color);

                Vector2 points[4];
                points[0] = (Vector2){q->begin.x, q->begin.y};
                points[1] = (Vector2){q->ctrl[0].x, q->ctrl[0].y};
                points[2] = (Vector2){q->ctrl[1].x, q->ctrl[1].y};
                points[3] = (Vector2){q->end.x, q->end.y};
                // TODO: Confirm NK_COMMAND_CURVE
                DrawLineStrip(points, 4, color);
            } break;

            case NK_COMMAND_ARC: {
                TraceLog(LOG_WARNING, "NUKLEAR: Untested implementation NK_COMMAND_ARC");
                const struct nk_command_arc *a = (const struct nk_command_arc *)cmd;
                color = nk_color_to_raylib_color(a->color);

                // TODO: Fix NK_COMMAND_ARC
                Vector2 center = {a->cx, a->cy};
                float radius = a->r;
                int startAngle = a->a[0];
                int endAngle = a->a[1];
                int segments = 20; // How many segments do we need?
                DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
            } break;

            case NK_COMMAND_ARC_FILLED: {
                // TODO: Fix NK_COMMAND_ARC_FILLED
                TraceLog(LOG_WARNING, "NUKLEAR: Untested implementation NK_COMMAND_ARC_FILLED");
                const struct nk_command_arc *a = (const struct nk_command_arc *)cmd;
                color = nk_color_to_raylib_color(a->color);

                Vector2 center = {a->cx, a->cy};
                float radius = a->r;
                int startAngle = a->a[0];
                int endAngle = a->a[1];
                int segments = 20; // How many segments do we need?
                DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
            } break;

            case NK_COMMAND_IMAGE: {
                // TODO: Fix NK_COMMAND_IMAGE
                TraceLog(LOG_WARNING, "NUKLEAR: Broken implementation NK_COMMAND_IMAGE");
                const struct nk_command_image *i = (const struct nk_command_image *)cmd;
                struct Image image;
                image.data = i->img.handle.ptr;
                image.width = i->w;
                image.height = i->h;
                image.mipmaps = 1;
                image.format = UNCOMPRESSED_R8G8B8A8;

                Texture texture = LoadTextureFromImage(image);
                Rectangle source = {0, 0, image.width, image.height};
                Rectangle dest = {i->x, i->y, i->w, i->h};
                Vector2 origin = {0, 0};
                float rotation = 0;
                Color tint = nk_color_to_raylib_color(i->col);
                DrawTexturePro(texture, source, dest, origin, rotation, tint);
                UnloadTexture(texture);
            } break;

            case NK_COMMAND_CUSTOM: {
                // TODO: NK_COMMAND_CUSTOM
                TraceLog(LOG_WARNING, "NUKLEAR: Missing implementation NK_COMMAND_CUSTOM");
            } break;

            default: {
                TraceLog(LOG_WARNING, "NUKLEAR: Missing implementation %i", cmd->type);
            } break;
        }
    }

    // Finish the scissor mode if it was in use.
    if (scissor_mode) {
        EndScissorMode();
    }

    nk_clear(ctx);
}

NK_API int
nk_raylib_translate_mouse_button(int button)
{
    switch (button) {
        case MOUSE_LEFT_BUTTON:
            return NK_BUTTON_LEFT;
        case MOUSE_RIGHT_BUTTON:
            return NK_BUTTON_RIGHT;
        case MOUSE_MIDDLE_BUTTON:
            return NK_BUTTON_MIDDLE;
    }

    return NK_BUTTON_MAX;
}

/**
 * Returns 1 when pressed, 2 when released, or 0 when no change.
 */
NK_API int nk_raylib_input_changed(int key) {
    if (IsKeyPressed(key)) {
        return 1;
    }
    else if (IsKeyReleased(key)) {
        return 0;
    }
    return -1;
}

NK_API void nk_raylib_input_keyboard(struct nk_context * ctx)
{
    int down;
    if ((down = nk_raylib_input_changed(KEY_LEFT_SHIFT)) >= 0) {
        nk_input_key(ctx, NK_KEY_SHIFT, down);
    }
    if ((down = nk_raylib_input_changed(KEY_RIGHT_SHIFT)) >= 0) {
        nk_input_key(ctx, NK_KEY_SHIFT, down);
    }
    if ((down = nk_raylib_input_changed(KEY_LEFT_CONTROL)) >= 0) {
        nk_input_key(ctx, NK_KEY_CTRL, down);
    }
    if ((down = nk_raylib_input_changed(KEY_RIGHT_CONTROL)) >= 0) {
        nk_input_key(ctx, NK_KEY_CTRL, down);
    }
    if ((down = nk_raylib_input_changed(KEY_DELETE)) >= 0) {
        nk_input_key(ctx, NK_KEY_DEL, down);
    }
    if ((down = nk_raylib_input_changed(KEY_ENTER)) >= 0) {
        nk_input_key(ctx, NK_KEY_ENTER, down);
    }
    if ((down = nk_raylib_input_changed(KEY_TAB)) >= 0) {
        nk_input_key(ctx, NK_KEY_TAB, down);
    }
    if ((down = nk_raylib_input_changed(KEY_BACKSPACE)) >= 0) {
        nk_input_key(ctx, NK_KEY_BACKSPACE, down);
    }
    if ((down = nk_raylib_input_changed(KEY_C)) >= 0) {
        nk_input_key(ctx, NK_KEY_COPY, (down == 1) && IsKeyDown(KEY_LEFT_CONTROL));
    }
    if ((down = nk_raylib_input_changed(KEY_X)) >= 0) {
        nk_input_key(ctx, NK_KEY_CUT, (down == 1) && IsKeyDown(KEY_LEFT_CONTROL));
    }
    if ((down = nk_raylib_input_changed(KEY_V)) >= 0) {
        nk_input_key(ctx, NK_KEY_PASTE, (down == 1) && IsKeyDown(KEY_LEFT_CONTROL));
    }
    if ((down = nk_raylib_input_changed(KEY_UP)) >= 0) {
        nk_input_key(ctx, NK_KEY_UP, down);
    }
    if ((down = nk_raylib_input_changed(KEY_DOWN)) >= 0) {
        nk_input_key(ctx, NK_KEY_DOWN, down);
    }
    if ((down = nk_raylib_input_changed(KEY_LEFT)) >= 0) {
        if (IsKeyDown(KEY_LEFT_CONTROL)) {
            nk_input_key(ctx, NK_KEY_TEXT_WORD_LEFT, down);
        }
        else {
            nk_input_key(ctx, NK_KEY_LEFT, down);
        }
    }
    if ((down = nk_raylib_input_changed(KEY_RIGHT)) >= 0) {
        if (IsKeyDown(KEY_LEFT_CONTROL)) {
            nk_input_key(ctx, NK_KEY_TEXT_WORD_RIGHT, down);
        }
        else {
            nk_input_key(ctx, NK_KEY_RIGHT, down);
        }
    }

    // TODO: Add remaining keyboard actions.
    // NK_KEY_TEXT_INSERT_MODE
    // NK_KEY_TEXT_REPLACE_MODE
    // NK_KEY_TEXT_RESET_MODE
    // NK_KEY_TEXT_LINE_START
    // NK_KEY_TEXT_LINE_END
    // NK_KEY_TEXT_START
    // NK_KEY_TEXT_END
    // NK_KEY_TEXT_UNDO
    // NK_KEY_TEXT_REDO
    // NK_KEY_TEXT_SELECT_ALL
    // NK_KEY_TEXT_WORD_LEFT
    // NK_KEY_TEXT_WORD_RIGHT
    // NK_KEY_SCROLL_START
    // NK_KEY_SCROLL_END
    // NK_KEY_SCROLL_DOWN
    // NK_KEY_SCROLL_UP

    // TODO: Verify that this unicode keyboard input works.
    for (int i = 32; i < 126; i++) {
        if (IsKeyPressed(i)) {
            nk_input_unicode(ctx, i);
        }
    }
}

NK_API void
nk_raylib_input(struct nk_context * ctx)
{
    nk_input_begin(ctx);

    enum nk_buttons id;

    // Mouse
    for (int button = MOUSE_LEFT_BUTTON; button <= MOUSE_MIDDLE_BUTTON; button++)
    {

          id = (nk_buttons) nk_raylib_translate_mouse_button(button);

       nk_input_button(ctx, id, GetMouseX(), GetMouseY(), IsMouseButtonDown(button));
    }
    nk_input_motion(ctx, GetMouseX(), GetMouseY());

    // Mouse Wheel
    int mouseWheel = GetMouseWheelMove();
    if (mouseWheel != 0) {
        struct nk_vec2 mouseWheelMove = (struct nk_vec2){0, mouseWheel};
        nk_input_scroll(ctx, mouseWheelMove);
    }

    nk_raylib_input_keyboard(ctx);

    nk_input_end(ctx);
}

NK_API void
nk_raylib_free(struct nk_context * ctx)
{
    // Unload the given font.
    struct Font* font = (struct Font*)ctx->style.font->userdata.ptr;
    if (font != NULL) {
        UnloadFont(*font);
    }

    // Unload the nuklear context.
    nk_free(ctx);
}

