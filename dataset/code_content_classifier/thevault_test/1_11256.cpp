size_t parse_schema(const std::string & buffer,
  std::vector<std::string> & column_names, 
  std::vector<flex_type_enum> & column_types)  {
  const char* iter = &buffer[0];
  // Initialize the correct number of columns
  const int num_cols = read_int(iter);
  //std::cerr << "number of columns: " << num_cols << std::endl;
  column_types.resize(num_cols);
  column_names.resize(num_cols);
  for (size_t i = 0; i < num_cols; ++i) {
    // Read the column name
    column_names[i] = read_string_msg(iter);
    // Read the column type description string
    const std::string type_desc = read_string_msg(iter);
    //std::cerr << "Parsing schema for: " << column_names[i] 
    //          << ", type: " << type_desc << std::endl;
    // Based on the string define the column type
    if (type_desc == "byte" || type_desc == "short" || 
        type_desc == "int" || type_desc == "bigint") {
      column_types[i] = flex_type_enum::INTEGER;
    } else if (type_desc == "float" || type_desc == "double") {
      column_types[i] = flex_type_enum::FLOAT;
    } else if (type_desc == "string") {
      column_types[i] = flex_type_enum::STRING;
    } else if (type_desc == "boolean") { // encode booleans as integers
      column_types[i] = flex_type_enum::INTEGER;
    } else if (type_desc == "array<float>" || 
               type_desc == "array<double>" 
               // || 
               // type_desc == "array<byte>" || // Not supported yet
               // type_desc == "array<char>" ||
               // type_desc == "array<int>" || 
               // type_desc == "array<bigint>" ||
               //type_desc == "array<boolean>"
               ) {
      column_types[i] = flex_type_enum::VECTOR;
    } else if (type_desc.substr(0,5) == "array") {
      column_types[i] = flex_type_enum::LIST;
    } else if (type_desc == "date" || type_desc == "timestamp") {
      column_types[i] = flex_type_enum::DATETIME;
    } else { // if the type is none of the above it could be
      column_types[i] = flex_type_enum::DICT;
    } // @TODO: add datetime type handling
    // we need to figure out what spark uses for datetime name
    //std::cerr << "Type: " << flex_type_enum_to_name(column_types[i]) << std::endl;
  }
  return num_cols;
}