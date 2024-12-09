inline void dump(const glTFTextureInfo* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->index, "index", js, err);
      if (val->texCoord != 0) dump_attr(val->texCoord, "texCoord", js, err);
    }