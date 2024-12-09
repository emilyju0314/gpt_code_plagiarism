inline void dump(const glTFAnimationChannel* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->sampler, "sampler", js, err);
      dump_attr(val->target, "target", js, err);
    }