inline void dump(const glTFSamplerMinFilter& val, json& js, parse_stack& err) {
      static map<glTFSamplerMinFilter, int> table = {
          {glTFSamplerMinFilter::Nearest, 9728},
          {glTFSamplerMinFilter::Linear, 9729},
          {glTFSamplerMinFilter::NearestMipmapNearest, 9984},
          {glTFSamplerMinFilter::LinearMipmapNearest, 9985},
          {glTFSamplerMinFilter::NearestMipmapLinear, 9986},
          {glTFSamplerMinFilter::LinearMipmapLinear, 9987},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }