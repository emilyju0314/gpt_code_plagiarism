inline void dump(const glTFTexture* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->sampler.is_valid()) dump_attr(val->sampler, "sampler", js, err);
      if (val->source.is_valid()) dump_attr(val->source, "source", js, err);
    }