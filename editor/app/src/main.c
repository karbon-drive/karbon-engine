#include <karbon/drive.h>
#include <karbon/app.h>
#include <karbon/utils.h>
#include <karbon/editor/renderer.h>


/* ------------------------------------------------------ Application Data -- */


struct app_ctx {
        /* renderer */
        ed_renderer_ctx_t rdr_ctx;
        struct ed_camera camera;
        struct ed_renderable renderables[1 << 2];
} app_ctx;


/* ----------------------------------------------------------- Application -- */


void
setup() {
        /* clear editor ctx */
        KD_MEMZERO(app_ctx);

        /* create various ctx's */
        app_ctx.rdr_ctx = ed_renderer_create(KD_NULL);
}


void
think() {
        /* render editor view */
        ed_renderer_render(
                app_ctx.rdr_ctx,
                &app_ctx.camera,
                KD_ARR_DATA(app_ctx.renderables),
                KD_ARR_COUNT(app_ctx.renderables));
}


void
shutdown() {
        /* destroy various ctx's */
        ed_renderer_destroy(app_ctx.rdr_ctx);

        /* clear editor ctx */
        KD_MEMZERO(app_ctx);
}


/* ----------------------------------------------- Application Description -- */


KD_APP_NAME("Karbon Editor")
KD_APP_DESC("Edits Data for Karbon")
KD_APP_GRAPHICS_API("OpenGL")
KD_APP_STARTUP_FN(setup)
KD_APP_TICK_FN(think)
KD_APP_SHUTDOWN_FN(shutdown)
