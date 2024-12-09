inline void dump_objverts(
        fstream& fs, const char* str, int nv, const obj_vertex* verts) {
      dump_val(fs, str);
      for (auto v = 0; v < nv; v++) {
        auto& vert = verts[v];
        auto vert_ptr = &vert.pos;
        auto nto_write = 0;
        for (auto i = 0; i < 5; i++) {
          if (vert_ptr[i] >= 0) nto_write = i + 1;
        }
        for (auto i = 0; i < nto_write; i++) {
          if (vert_ptr[i] >= 0) {
            dump_val(fs, ((i == 0) ? ' ' : '/'));
            dump_val(fs, vert_ptr[i] + 1);
          } else {
            dump_val(fs, '/');
          }
        }
      }
      dump_val(fs, '\n');
    }