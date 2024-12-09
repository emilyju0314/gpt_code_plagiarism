inline void dump(const glTFMaterialAlphaMode& val, json& js, parse_stack& err) {
      static map<glTFMaterialAlphaMode, string> table = {
          {glTFMaterialAlphaMode::Opaque, "OPAQUE"},
          {glTFMaterialAlphaMode::Mask, "MASK"},
          {glTFMaterialAlphaMode::Blend, "BLEND"},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }