void initialize_schema_variables(const bool is_dataframe,
                                 const bool is_batch_mode,
                                 const std::string & buffer,
                                 std::vector<std::string> & column_names,
                                 std::vector<flex_type_enum> & column_types,
                                 std::vector<flexible_type> & row_buffer,
                                 bool is_utf8_string) {
  if (is_dataframe) {
    // if its a datafame than the buffer contains the schema information
    parse_schema(buffer, column_names, column_types);
  } else { 
    // this is not a dataframe so we need to infer the schema by
    // looking at the types stored in the rows.
    flexible_type flex_obj;
    if (is_utf8_string) { 
      flex_obj = flex_string(&buffer[0],buffer.size());
    } else {
      flex_obj = read_flex_obj(buffer);
      python::check_for_python_exception();
    }
    flexible_type first_row;
    // @todo: document this code (it makes no sense).
    if (is_batch_mode) {
      if (flex_obj.get_type() == flex_type_enum::LIST) {
        first_row = flex_obj.get<flex_list>()[0];
      } else { 
        // assert(flex_obj.get_type() == flex_type_enum::VECTOR)
        first_row = flex_obj[0];
      }
    } else {
      first_row = flex_obj;
    }
    // Infer the schema for the first row
    infer_schema(first_row, is_dataframe, column_names, column_types);   
  }
  // Initialize the row buffer based on the inferred type information
  initialize_row_buffer(column_types, row_buffer);
}