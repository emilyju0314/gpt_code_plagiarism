inline void dump(const glTFCamera* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->orthographic != nullptr)
        dump_attr(val->orthographic, "orthographic", js, err);
      if (val->perspective != nullptr)
        dump_attr(val->perspective, "perspective", js, err);
      dump_attr(val->type, "type", js, err);
    }