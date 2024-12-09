inline void dump(const glTFAsset* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      if (val->copyright != "") dump_attr(val->copyright, "copyright", js, err);
      if (val->generator != "") dump_attr(val->generator, "generator", js, err);
      dump_attr(val->version, "version", js, err);
      if (val->minVersion != "")
        dump_attr(val->minVersion, "minVersion", js, err);
    }