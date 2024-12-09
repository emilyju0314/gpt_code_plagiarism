inline void dump(const glTFSkin* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->inverseBindMatrices.is_valid())
        dump_attr(val->inverseBindMatrices, "inverseBindMatrices", js, err);
      if (val->skeleton.is_valid()) dump_attr(val->skeleton, "skeleton", js, err);
      dump_attr(val->joints, "joints", js, err);
    }