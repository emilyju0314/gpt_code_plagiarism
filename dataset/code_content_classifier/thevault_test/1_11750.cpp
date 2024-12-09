inline void dump(const glTFAccessorSparseIndicesComponentType& val, json& js,
                     parse_stack& err) {
      static map<glTFAccessorSparseIndicesComponentType, int> table = {
          {glTFAccessorSparseIndicesComponentType::UnsignedByte, 5121},
          {glTFAccessorSparseIndicesComponentType::UnsignedShort, 5123},
          {glTFAccessorSparseIndicesComponentType::UnsignedInt, 5125},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }