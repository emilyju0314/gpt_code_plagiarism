inline void dump(
        const glTFAnimationSamplerInterpolation& val, json& js, parse_stack& err) {
      static map<glTFAnimationSamplerInterpolation, string> table = {
          {glTFAnimationSamplerInterpolation::Linear, "LINEAR"},
          {glTFAnimationSamplerInterpolation::Step, "STEP"},
          {glTFAnimationSamplerInterpolation::CatmullRomSpline,
                                                      "CATMULLROMSPLINE"},
          {glTFAnimationSamplerInterpolation::CubicSpline, "CUBICSPLINE"},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }