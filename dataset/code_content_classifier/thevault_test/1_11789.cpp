inline void dump(const glTFSampler* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->magFilter != glTFSamplerMagFilter::NotSet)
        dump_attr(val->magFilter, "magFilter", js, err);
      if (val->minFilter != glTFSamplerMinFilter::NotSet)
        dump_attr(val->minFilter, "minFilter", js, err);
      if (val->wrapS != glTFSamplerWrapS::Repeat)
        dump_attr(val->wrapS, "wrapS", js, err);
      if (val->wrapT != glTFSamplerWrapT::Repeat)
        dump_attr(val->wrapT, "wrapT", js, err);
    }