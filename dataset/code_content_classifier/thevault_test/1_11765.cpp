inline void dump(const glTFBufferViewTarget& val, json& js, parse_stack& err) {
      static map<glTFBufferViewTarget, int> table = {
          {glTFBufferViewTarget::ArrayBuffer, 34962},
          {glTFBufferViewTarget::ElementArrayBuffer, 34963},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }