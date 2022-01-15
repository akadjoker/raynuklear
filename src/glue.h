
#ifndef BB_NUKLEAR_H
#define BB_NUKLEAR_H
#include <stdint.h>
#include <rlgl.h>

//#define NK_INCLUDE_FIXED_TYPES
//#define NK_INCLUDE_STANDARD_IO
//#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
//#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
//#define NK_INCLUDE_FONT_BAKING
//#define NK_INCLUDE_DEFAULT_FONT

#include "nuklear.h"

NK_API struct nk_context* nk_raylib_init();
NK_API void nk_raylib_input(struct nk_context * ctx);
NK_API void nk_raylib_render(struct nk_context * ctx);
NK_API Color nk_color_to_raylib_color(struct nk_color color);
NK_API int nk_raylib_translate_mouse_button(int button);
NK_API void nk_raylib_free(struct nk_context * ctx);
NK_API Color nk_colorf_to_raylib_color(struct nk_colorf color);

#endif
