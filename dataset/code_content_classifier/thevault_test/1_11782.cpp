inline void dump(const glTFMeshPrimitive* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->attributes, "attributes", js, err);
      if (val->indices.is_valid()) dump_attr(val->indices, "indices", js, err);
      if (val->material.is_valid()) dump_attr(val->material, "material", js, err);
      if (val->mode != glTFMeshPrimitiveMode::Triangles)
        dump_attr(val->mode, "mode", js, err);
      if (!val->targets.empty()) dump_attr(val->targets, "targets", js, err);
    }