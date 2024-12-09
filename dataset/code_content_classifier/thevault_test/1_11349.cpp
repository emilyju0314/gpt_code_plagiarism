void typed_encode(const std::vector<flexible_type>& data, 
                  block_info& block,
                  oarchive& oarc) {
  block.flags |= IS_FLEXIBLE_TYPE;
  block.num_elem = data.size();
 
  // figure out how many types there are in the array 
  graphlab::fixed_dense_bitset<16> types_appeared;
  types_appeared.clear();
  for (size_t i = 0;i < data.size(); ++i) {
    types_appeared.set_bit_unsync((char)data[i].get_type());
  }

  // write one byte for the number of types in the block
  char num_types = types_appeared.popcount();
  oarc << num_types;
  bool perform_type_encoding = true;
  if (num_types == 0) {
    // no types. no array. nothing. quit
    block.block_size = oarc.off;
    return;
  } if (num_types == 1) {
    // One type. array has only one type
    oarc << (char)data[0].get_type();
    // entire block is of UNDEFINED values. quit.
    if (data[0].get_type() == flex_type_enum::UNDEFINED) {
      block.block_size = oarc.off;
      return;
    }
  } else if (num_types == 2 && types_appeared.get((char)flex_type_enum::UNDEFINED)) {
    // two types, one of them must be UNDEFINED
    // write that type.
    for(auto t: types_appeared) {
      if ((flex_type_enum)t != flex_type_enum::UNDEFINED) {
        oarc << (char)(t);
        break;
      }
    }
    // then write a bit field containing the positions of the UNDEFINED bits.
    graphlab::dense_bitset d(data.size());
    d.clear();
    for (size_t i = 0;i < data.size(); ++i) {
      if (data[i].get_type() == flex_type_enum::UNDEFINED) d.set_bit_unsync(i);
    }
    oarc.write((char*)d.array, sizeof(size_t) * d.arrlen);
  } else {
    oarc << data;
    perform_type_encoding = false;
    block.flags |= MULTIPLE_TYPE_BLOCK;
  }
  if (perform_type_encoding) {
    if (types_appeared.get((char)flex_type_enum::INTEGER)) {
      encode_number(block, oarc, data);
    } else if(types_appeared.get((char)flex_type_enum::FLOAT)) {
      block.flags |=  BLOCK_ENCODING_EXTENSION;
      encode_double(block, oarc, data);
    } else if (types_appeared.get((char)flex_type_enum::STRING)) {
      encode_string(block, oarc, data);
    } else if (types_appeared.get((char)flex_type_enum::VECTOR)) {
      block.flags |=  BLOCK_ENCODING_EXTENSION;
      encode_vector(block, oarc, data);
    } else {
      flexible_type_impl::serializer s{oarc};
      for (size_t i = 0;i < data.size(); ++i) {
        if (data[i].get_type() != flex_type_enum::UNDEFINED) {
          data[i].apply_visitor(s);
        }
      }
    }
  }
  block.block_size = oarc.off;
}