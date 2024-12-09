inline void dump(
        const glTFAnimationChannelTargetPath& val, json& js, parse_stack& err) {
      static map<glTFAnimationChannelTargetPath, string> table = {
          {glTFAnimationChannelTargetPath::Translation, "translation"},
          {glTFAnimationChannelTargetPath::Rotation, "rotation"},
          {glTFAnimationChannelTargetPath::Scale, "scale"},
          {glTFAnimationChannelTargetPath::Weights, "weights"},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }