inline void dump(const glTFAccessor* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->bufferView.is_valid())
        dump_attr(val->bufferView, "bufferView", js, err);
      if (val->byteOffset != 0) dump_attr(val->byteOffset, "byteOffset", js, err);
      dump_attr(val->componentType, "componentType", js, err);
      if (val->normalized != false)
        dump_attr(val->normalized, "normalized", js, err);
      dump_attr(val->count, "count", js, err);
      dump_attr(val->type, "type", js, err);
      if (!val->max.empty()) dump_attr(val->max, "max", js, err);
      if (!val->min.empty()) dump_attr(val->min, "min", js, err);
      if (val->sparse != nullptr) dump_attr(val->sparse, "sparse", js, err);
    }