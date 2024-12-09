inline void dump(const glTFAnimation* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      dump_attr(val->channels, "channels", js, err);
      dump_attr(val->samplers, "samplers", js, err);
    }