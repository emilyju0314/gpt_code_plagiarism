inline void dump(const glTFProperty* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
#if YGL_GLTFJSON
      if (!val->extensions.empty())
        dump_attr(val->extensions, "extensions", js, err);
    if (!val->extras.is_null()) dump_attr(val->extras, "extras", js, err);
#endif
    }