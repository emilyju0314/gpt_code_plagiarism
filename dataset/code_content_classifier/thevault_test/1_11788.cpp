inline void dump(const glTFSamplerWrapT& val, json& js, parse_stack& err) {
      static map<glTFSamplerWrapT, int> table = {
          {glTFSamplerWrapT::ClampToEdge, 33071},
          {glTFSamplerWrapT::MirroredRepeat, 33648},
          {glTFSamplerWrapT::Repeat, 10497},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }