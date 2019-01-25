

#include <karbon/editor/renderer.h>


/* -------------------------------------------------------------- Lifetime -- */


ed_renderer_ctx_t
ed_renderer_create(
        struct ed_renderer_desc *desc)
{
        (void)desc;
        return 0;
}


int
ed_renderer_destroy(
        ed_renderer_ctx_t *ctx)
{
        (void)ctx;
        return 0;
}
