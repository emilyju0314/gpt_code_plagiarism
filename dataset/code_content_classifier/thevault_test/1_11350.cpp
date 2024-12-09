bool typed_decode(const block_info& info,
                  char* start, size_t len,
                  std::vector<flexible_type>& ret) {
  if (!(info.flags & IS_FLEXIBLE_TYPE)) {
    logstream(LOG_ERROR) << "Attempting to decode a non-typed block"
                         << std::endl;
    return false;
  }
  graphlab::iarchive iarc(start, len);

  size_t dsize = info.num_elem;
  ret.resize(dsize);
  char num_types; iarc >> num_types;
  flex_type_enum column_type;
  size_t num_undefined = 0;
  // if it is a multiple type block, we don't perform a type decode
  bool perform_type_decoding = !(info.flags & MULTIPLE_TYPE_BLOCK);
  if (perform_type_decoding) {
    if (num_types == 0) {
      // empty block
      return true;
    } else if (num_types == 1) {
      //  one block of contiguous type. quit
      char c;
      iarc >> c;
      column_type = (flex_type_enum)c;
      for (size_t i = 0;i < dsize; ++i) {
        ret[i].reset(column_type);
      }
      // all undefined. quit
      if (column_type == flex_type_enum::UNDEFINED) return true;
    } else if (num_types == 2) {
      // two types, but with undefined entries.
      char c;
      iarc >> c;
      column_type = (flex_type_enum)c;
      for (size_t i = 0;i < dsize; ++i) {
        ret[i].reset(column_type);
      }
      // read the bitset and undefine all the flagged entries
      graphlab::dense_bitset d(info.num_elem);
      d.clear();
      iarc.read((char*)d.array, sizeof(size_t)*d.arrlen);
      for (auto t: d) {
        ret[t].reset(flex_type_enum::UNDEFINED);
      }
      num_undefined = d.popcount();
    }
  } else {
    iarc >> ret;
  }
  if (perform_type_decoding) {
    // type decode
    if (column_type == flex_type_enum::INTEGER) {
      decode_number(iarc, ret, num_undefined);
    } else if (column_type == flex_type_enum::FLOAT) {
      if (info.flags & BLOCK_ENCODING_EXTENSION) {
        decode_double(iarc, ret, num_undefined);
      } else {
        decode_double_legacy(iarc, ret, num_undefined);
      }
    } else if (column_type == flex_type_enum::STRING) {
      decode_string(iarc, ret, num_undefined);
    } else if (column_type == flex_type_enum::VECTOR) {
      decode_vector(iarc, ret, num_undefined, 
                    info.flags & BLOCK_ENCODING_EXTENSION);
    } else {
      flexible_type_impl::deserializer s{iarc};
      for (size_t i = 0;i < dsize; ++i) {
        if (ret[i].get_type() != flex_type_enum::UNDEFINED) {
          ret[i].apply_mutating_visitor(s);
        }
      }
    }
  }

  if (ret.size() != info.num_elem) {
    logstream(LOG_ERROR) << "Unexpected number of elements read. "
                         << "Read " << ret.size() 
                         << ". Expecting " << info.num_elem << std::endl;
    return false;
  }
  return true;
}