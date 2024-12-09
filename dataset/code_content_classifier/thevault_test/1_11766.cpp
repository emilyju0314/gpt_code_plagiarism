inline void dump(const glTFBufferView* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      dump_attr(val->buffer, "buffer", js, err);
      if (val->byteOffset != 0) dump_attr(val->byteOffset, "byteOffset", js, err);
      dump_attr(val->byteLength, "byteLength", js, err);
      if (val->byteStride != 0) dump_attr(val->byteStride, "byteStride", js, err);
      if (val->target != glTFBufferViewTarget::NotSet)
        dump_attr(val->target, "target", js, err);
    }