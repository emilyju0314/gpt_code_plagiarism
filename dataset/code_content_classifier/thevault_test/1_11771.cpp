inline void dump(const glTFImageMimeType& val, json& js, parse_stack& err) {
      static map<glTFImageMimeType, string> table = {
          {glTFImageMimeType::ImageJpeg, "image/jpeg"},
          {glTFImageMimeType::ImagePng, "image/png"},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }