void initialize_row_buffer(const std::vector<flex_type_enum> & column_types, 
                           std::vector<flexible_type> & row_buffer) { 
  // Resize the tokens to match the number columns (populating with strings as a default)
  row_buffer.resize(column_types.size()); //, flex_string());       
  // Fill in the tokens with the correct type
  size_t ncols = column_types.size();
  for(size_t i = 0;i < ncols; ++i) {
    //    if(column_types[i] != flex_type_enum::STRING)
    row_buffer[i].reset(column_types[i]);
    // std::cerr << "Tokens: " << flex_type_enum_to_name(column_types[i]) << std::endl;
  }
}