inline void dump(const glTFCameraPerspective* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      if (val->aspectRatio != 0)
        dump_attr(val->aspectRatio, "aspectRatio", js, err);
      dump_attr(val->yfov, "yfov", js, err);
      if (val->zfar != 0) dump_attr(val->zfar, "zfar", js, err);
      dump_attr(val->znear, "znear", js, err);
    }