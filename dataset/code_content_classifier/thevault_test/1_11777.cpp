inline void dump(
        const glTFMaterialPbrMetallicRoughness* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      if (val->baseColorFactor != vec4f{1, 1, 1, 1})
        dump_attr(val->baseColorFactor, "baseColorFactor", js, err);
      if (val->baseColorTexture != nullptr)
        dump_attr(val->baseColorTexture, "baseColorTexture", js, err);
      if (val->metallicFactor != 1)
        dump_attr(val->metallicFactor, "metallicFactor", js, err);
      if (val->roughnessFactor != 1)
        dump_attr(val->roughnessFactor, "roughnessFactor", js, err);
      if (val->metallicRoughnessTexture != nullptr)
        dump_attr(
            val->metallicRoughnessTexture, "metallicRoughnessTexture", js, err);
    }