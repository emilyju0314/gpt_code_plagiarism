inline void dump(
        const glTFCameraOrthographic* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->xmag, "xmag", js, err);
      dump_attr(val->ymag, "ymag", js, err);
      dump_attr(val->zfar, "zfar", js, err);
      dump_attr(val->znear, "znear", js, err);
    }