#ifndef CTX_INCLUDED
#define CTX_INCLUDED

#include <stdint.h>


struct ed_mesh {
        /* array */ float * mesh_data;
        /* array */ unsigned int * mesh_index;
};


struct ed_texture {
        /* array */ uint8_t * texture_data;
};


struct ed_renderer_ctx {
        /* array */ uint64_t * mesh_keys;
        /* array */ struct ed_mesh * meshes;

        /* array */ uint64_t * texture_keys;
        /* array */ struct ed_texture * textures;
};


/* inc guard */
#endif
