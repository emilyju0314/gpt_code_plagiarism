inline void dump(const glTFAnimationSampler* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->input, "input", js, err);
      if (val->interpolation != glTFAnimationSamplerInterpolation::Linear)
        dump_attr(val->interpolation, "interpolation", js, err);
      dump_attr(val->output, "output", js, err);
    }