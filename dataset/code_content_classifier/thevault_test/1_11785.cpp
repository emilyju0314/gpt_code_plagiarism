inline void dump(const glTFSamplerMagFilter& val, json& js, parse_stack& err) {
      static map<glTFSamplerMagFilter, int> table = {
          {glTFSamplerMagFilter::Nearest, 9728},
          {glTFSamplerMagFilter::Linear, 9729},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }