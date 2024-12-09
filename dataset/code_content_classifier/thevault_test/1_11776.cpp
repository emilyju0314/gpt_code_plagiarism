inline void dump(
        const glTFMaterialOcclusionTextureInfo* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFTextureInfo*)val, js, err);
      if (val->strength != 1) dump_attr(val->strength, "strength", js, err);
    }