inline void dump(const glTFAccessorType& val, json& js, parse_stack& err) {
      static map<glTFAccessorType, string> table = {
          {glTFAccessorType::Scalar, "SCALAR"},
          {glTFAccessorType::Vec2, "VEC2"},
          {glTFAccessorType::Vec3, "VEC3"},
          {glTFAccessorType::Vec4, "VEC4"},
          {glTFAccessorType::Mat2, "MAT2"},
          {glTFAccessorType::Mat3, "MAT3"},
          {glTFAccessorType::Mat4, "MAT4"},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }