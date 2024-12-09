inline void dump(
        const glTFMaterialPbrSpecularGlossiness* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      if (val->diffuseFactor != vec4f{1, 1, 1, 1})
        dump_attr(val->diffuseFactor, "diffuseFactor", js, err);
      if (val->diffuseTexture != nullptr)
        dump_attr(val->diffuseTexture, "diffuseTexture", js, err);
      if (val->specularFactor != vec3f{1, 1, 1})
        dump_attr(val->specularFactor, "specularFactor", js, err);
      if (val->glossinessFactor != 1)
        dump_attr(val->glossinessFactor, "glossinessFactor", js, err);
      if (val->specularGlossinessTexture != nullptr)
        dump_attr(val->specularGlossinessTexture, "specularGlossinessTexture",
                  js, err);
    }