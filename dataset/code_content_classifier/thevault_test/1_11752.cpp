inline void dump(
        const glTFAccessorSparseValues* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      dump_attr(val->bufferView, "bufferView", js, err);
      if (val->byteOffset != 0) dump_attr(val->byteOffset, "byteOffset", js, err);
    }