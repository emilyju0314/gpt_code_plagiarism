inline void dump(
        const glTFMaterialNormalTextureInfo* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFTextureInfo*)val, js, err);
      if (val->scale != 1) dump_attr(val->scale, "scale", js, err);
    }