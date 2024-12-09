inline void dump(const glTFBuffer* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->uri != "") dump_attr(val->uri, "uri", js, err);
      dump_attr(val->byteLength, "byteLength", js, err);
    }