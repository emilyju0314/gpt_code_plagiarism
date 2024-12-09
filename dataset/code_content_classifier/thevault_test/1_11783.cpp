inline void dump(const glTFMesh* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      dump_attr(val->primitives, "primitives", js, err);
      if (!val->weights.empty()) dump_attr(val->weights, "weights", js, err);
    }