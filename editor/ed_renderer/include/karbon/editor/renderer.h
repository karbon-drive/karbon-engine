#ifndef ED_RENDERER_INCLUDED
#define ED_RENDERER_INCLUDED


#include <stdint.h>


typedef struct kded_renderer_ctx * kded_renderer_ctx_t;


struct kded_renderable {
        float world_mat[16];
        float aabb[6];
        uint64_t mesh_id;
};


struct kded_camera {
        float view_mat[16];
};


kded_renderer_ctx_t
kded_renderer_create();


int
kded_renderer_destroy(
        kded_renderer_ctx_t *ctx);


int
kded_renderer_load(
        kded_renderer_ctx_t ctx,
        const char *filename);


int
kded_renderer_render(
        kded_renderer_ctx_t ctx,
        struct kded_camera *camera,
        struct kded_renderables *renderables,
        int renderables_count);


#endif

