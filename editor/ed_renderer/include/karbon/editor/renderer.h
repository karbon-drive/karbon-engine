#ifndef ED_RENDERER_INCLUDED
#define ED_RENDERER_INCLUDED


#include <stdint.h>


/* ----------------------------------------------------------------- Types -- */


typedef struct ed_renderer_ctx * ed_renderer_ctx_t;


/* -------------------------------------------------------------- Lifetime -- */


ed_renderer_ctx_t
ed_renderer_create();


int
ed_renderer_destroy(
        ed_renderer_ctx_t *ctx);


/* ------------------------------------------------------------- Resources -- */


uint64_t
ed_renderer_load(
        ed_renderer_ctx_t ctx,
        const char *filename);


/* ---------------------------------------------------------------- Render -- */


struct ed_renderable {
        float world_mat[16];
        float aabb[6];
        uint64_t mesh_id;
};


struct ed_camera {
        float view_mat[16];
        float cutoff_distance;
};


int
ed_renderer_render(
        ed_renderer_ctx_t ctx,
        struct ed_camera *camera,
        struct ed_renderables *renderables,
        int renderables_count);


/* inc guard */
#endif
