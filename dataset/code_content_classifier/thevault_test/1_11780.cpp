inline void dump(const glTFMaterial* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->pbrMetallicRoughness != nullptr)
        dump_attr(val->pbrMetallicRoughness, "pbrMetallicRoughness", js, err);
      if (val->normalTexture != nullptr)
        dump_attr(val->normalTexture, "normalTexture", js, err);
      if (val->occlusionTexture != nullptr)
        dump_attr(val->occlusionTexture, "occlusionTexture", js, err);
      if (val->emissiveTexture != nullptr)
        dump_attr(val->emissiveTexture, "emissiveTexture", js, err);
      if (val->emissiveFactor != vec3f{0, 0, 0})
        dump_attr(val->emissiveFactor, "emissiveFactor", js, err);
      if (val->alphaMode != glTFMaterialAlphaMode::Opaque)
        dump_attr(val->alphaMode, "alphaMode", js, err);
      if (val->alphaCutoff != 0.5)
        dump_attr(val->alphaCutoff, "alphaCutoff", js, err);
      if (val->doubleSided != false)
        dump_attr(val->doubleSided, "doubleSided", js, err);

      if (val->pbrSpecularGlossiness != nullptr) {
        auto& js_ext = js["extensions"];
        dump_attr(val->pbrSpecularGlossiness,
                  "KHR_materials_pbrSpecularGlossiness", js_ext, err);
      }
    }