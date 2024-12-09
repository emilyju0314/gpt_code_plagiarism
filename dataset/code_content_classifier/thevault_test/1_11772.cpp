inline void dump(const glTFImage* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->uri != "") dump_attr(val->uri, "uri", js, err);
      if (val->mimeType != glTFImageMimeType::NotSet)
        dump_attr(val->mimeType, "mimeType", js, err);
      if (val->bufferView.is_valid())
        dump_attr(val->bufferView, "bufferView", js, err);
    }