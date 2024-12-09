inline void dump(
        const glTFAnimationChannelTarget* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->node, "node", js, err);
      dump_attr(val->path, "path", js, err);
    }