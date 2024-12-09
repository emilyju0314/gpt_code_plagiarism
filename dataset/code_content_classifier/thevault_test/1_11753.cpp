inline void dump(const glTFAccessorSparse* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->count, "count", js, err);
      dump_attr(val->indices, "indices", js, err);
      dump_attr(val->values, "values", js, err);
    }