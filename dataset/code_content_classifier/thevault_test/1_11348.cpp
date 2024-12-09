static void decode_vector(iarchive& iarc, 
                          std::vector<flexible_type>& ret,
                          size_t num_undefined, 
                          bool new_format) {
  unsigned int last_id = 0;
  decode_vector_stream(ret.size() - num_undefined, iarc, 
                       [&](flexible_type val) {
                         while(last_id < ret.size() && 
                               ret[last_id].get_type() == flex_type_enum::UNDEFINED) {
                           ++last_id;
                         }
                         ret[last_id] = val;
                         DASSERT_LT(last_id, ret.size());
                         ++last_id;
                       }, new_format);
}