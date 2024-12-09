static bool typed_decode_stream_callback(const block_info& info,
                                  char* start, size_t len,
                                  Fn callback) {
  if (!(info.flags & IS_FLEXIBLE_TYPE)) {
    logstream(LOG_ERROR) << "Attempting to decode a non-typed block"
                         << std::endl;
    return false;
  }
  graphlab::iarchive iarc(start, len);

  // some basic block properties which will be filled in
  // number of elements
  size_t dsize = info.num_elem;
  // column type
  flex_type_enum column_type;
  // num undefined.
  size_t num_undefined = 0;
  // undefined bitmap mapping out where are the undefined values.
  // only specified if num_undefined > 0
  graphlab::dense_bitset undefined_bitmap;

  char num_types; 
  iarc >> num_types;
  // if it is a multiple type block, we don't perform a type decode
  bool perform_type_decoding = !(info.flags & MULTIPLE_TYPE_BLOCK);
  if (perform_type_decoding) {
    if (num_types == 0) {
      // empty block
      return true;
    } else if (num_types == 1) {
      //  one block of contiguous type. 
      char c;
      iarc >> c;
      column_type = (flex_type_enum)c;
      // all undefined. generate and return
      if (column_type == flex_type_enum::UNDEFINED) {
        for (size_t i = 0;i < dsize; ++i) callback(FLEX_UNDEFINED);
        return true;
      }
    } else if (num_types == 2) {
      // two types, but with undefined entries.
      char c;
      iarc >> c;
      column_type = (flex_type_enum)c;
      // read the bitset and undefine all the flagged entries
      undefined_bitmap.resize(info.num_elem);
      undefined_bitmap.clear();
      iarc.read((char*)undefined_bitmap.array, sizeof(size_t)*undefined_bitmap.arrlen);
      num_undefined = undefined_bitmap.popcount();
    }
  } else {
    std::vector<flexible_type> values;
    iarc >> values;
    for (const auto& i: values) {
      callback(i);
    }
  }

  if (perform_type_decoding) {
    int last_id = 0;
    auto stream_callback = 
        [&](const flexible_type& val) {
          // generate all the undefined
          if (num_undefined) {
            while(last_id < dsize && 
                  undefined_bitmap.get(last_id)) {
              callback(FLEX_UNDEFINED);
              ++last_id;
            }
          }
          callback(val);
          ++last_id;
        };
    size_t elements_to_decode = dsize - num_undefined;
    if (column_type == flex_type_enum::INTEGER) {
      decode_number_stream(elements_to_decode, iarc, stream_callback); 
    } else if (column_type == flex_type_enum::FLOAT) {
      if (info.flags & BLOCK_ENCODING_EXTENSION) {
        decode_double_stream(elements_to_decode, iarc, stream_callback); 
      } else {
        decode_double_stream_legacy(elements_to_decode, iarc, stream_callback); 
      }
    } else if (column_type == flex_type_enum::STRING) {
      decode_string_stream(elements_to_decode, iarc, stream_callback); 
    } else if (column_type == flex_type_enum::VECTOR) {
      decode_vector_stream(elements_to_decode, iarc, stream_callback, 
                           info.flags & BLOCK_ENCODING_EXTENSION); 
    } else {
      flexible_type_impl::deserializer s{iarc};
      flexible_type ret(column_type);
      for (size_t i = 0;i < dsize; ++i) {
        if (num_undefined && undefined_bitmap.get(i)) {
          callback(FLEX_UNDEFINED);
        } else {
          ret.apply_mutating_visitor(s);
          callback(ret);
        }
      }
    }
    // generate the final undefined values
    if (num_undefined) {
      while(last_id < dsize && 
            undefined_bitmap.get(last_id)) {
        callback(FLEX_UNDEFINED);
        ++last_id;
      }
    }
  }
  return true;
}