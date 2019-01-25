#include <karbon/drive.h>
#include <karbon/app.h>
#include <karbon/utils.h>
#include <karbon/editor/renderer.h>
#include <GL/gl3w.h>
#include <assert.h>


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
        /* setup system */
        if (gl3wInit()) {
                assert(!"FAILED TO INIT");
        }
        assert(gl3wIsSupported(3, 2));

        /* clear editor ctx */
        KD_MEMZERO(app_ctx);

        /* create ctx's */
        app_ctx.rdr_ctx = ed_renderer_create(KD_NULL);
}


void
think() {
        kd_result ok = KD_RESULT_OK;

        /* fetch events */
        uint64_t events = 0;
        ok = kd_events_get(&events);
        assert(ok == KD_RESULT_OK && "Failed to get events");

        /* input */
        if(events & KD_EVENT_INPUT_KB) {
                struct kd_keyboard_desc desc;
                ok = kd_input_get_keyboards(&desc);
                assert(ok == KD_RESULT_OK && "Failed to get KB");

                uint8_t ks = desc.kb_state[0][KD_KB_ESC];

                if(ks & KD_KEY_UP_EVENT) {
                        ok = kd_ctx_close();
                        assert(ok == KD_RESULT_OK && "Failed to quit");
                }
        }

        glClearColor(1,0,1,1);
        glClear(GL_COLOR_BUFFER_BIT);

        /* render editor view */
        ed_renderer_render(
                app_ctx.rdr_ctx,
                &app_ctx.camera,
                KD_ARR_DATA(app_ctx.renderables),
                KD_ARR_COUNT(app_ctx.renderables));
}


void
shutdown() {
        /* destroy ctx's */
        ed_renderer_destroy(&app_ctx.rdr_ctx);

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
