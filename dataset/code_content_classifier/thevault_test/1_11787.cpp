inline void dump(const glTFSamplerWrapS& val, json& js, parse_stack& err) {
      static map<glTFSamplerWrapS, int> table = {
          {glTFSamplerWrapS::ClampToEdge, 33071},
          {glTFSamplerWrapS::MirroredRepeat, 33648},
          {glTFSamplerWrapS::Repeat, 10497},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }