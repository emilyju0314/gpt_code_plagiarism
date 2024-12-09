inline void dump(
        const glTFChildOfRootProperty* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      if (val->name != "") dump_attr(val->name, "name", js, err);
    }