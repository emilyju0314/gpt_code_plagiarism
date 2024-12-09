inline void dump(const glTFCameraType& val, json& js, parse_stack& err) {
      static map<glTFCameraType, string> table = {
          {glTFCameraType::Perspective, "perspective"},
          {glTFCameraType::Orthographic, "orthographic"},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }