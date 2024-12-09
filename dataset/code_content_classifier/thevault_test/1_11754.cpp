inline void dump(
        const glTFAccessorComponentType& val, json& js, parse_stack& err) {
      static map<glTFAccessorComponentType, int> table = {
          {glTFAccessorComponentType::Byte, 5120},
          {glTFAccessorComponentType::UnsignedByte, 5121},
          {glTFAccessorComponentType::Short, 5122},
          {glTFAccessorComponentType::UnsignedShort, 5123},
          {glTFAccessorComponentType::UnsignedInt, 5125},
          {glTFAccessorComponentType::Float, 5126},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }