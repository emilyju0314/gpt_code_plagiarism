inline void dump(const glTFScene* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (!val->nodes.empty()) dump_attr(val->nodes, "nodes", js, err);
    }