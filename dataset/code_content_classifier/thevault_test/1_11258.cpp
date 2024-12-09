void infer_schema(const flexible_type & row, 
                  bool is_dataframe,
                  std::vector<std::string> & column_names,
                  std::vector<flex_type_enum> & column_types) {
  size_t ncols = 1; 
  if(is_dataframe && row.get_type() == flex_type_enum::DICT) { 
    flex_dict dict = row.get<flex_dict>();
    ncols = dict.size();
    column_names.resize(ncols);
    column_types.resize(ncols);

    for (size_t i = 0;i < ncols; ++i) {
      column_names[i] = dict[i].first.get<flex_string>();
      column_types[i] = dict[i].second.get_type();
      if(column_types[i] == flex_type_enum::UNDEFINED) {
        column_types[i] = flex_type_enum::STRING;
      }
    }
  } else if(is_dataframe && row.get_type() == flex_type_enum::LIST) { 
    flex_list rec = row.get<flex_list>();
    ncols = rec.size();
    column_names.resize(ncols);
    column_types.resize(ncols);
    for(size_t i = 0;i < ncols; ++i) {
      column_names[i] = "X"+ std::to_string(i + 1);
      column_types[i] = rec[i].get_type();
      if(column_types[i] == flex_type_enum::UNDEFINED) {
        column_types[i] = flex_type_enum::STRING;
      }
    }
  } else if(is_dataframe && row.get_type() == flex_type_enum::VECTOR) { 
    flex_vec vec = row.get<flex_vec>();
    ncols = vec.size();
    column_names.resize(ncols);
    column_types.resize(ncols);
    for(size_t i = 0;i < ncols; ++i) {
      column_names[i] = "X"+ std::to_string(i + 1);
      column_types[i] = flex_type_enum::FLOAT;
    }
  } else { 
    column_names.resize(ncols); 
    column_types.resize(ncols);
    column_types[0] = row.get_type();
    if(column_types[0] == flex_type_enum::UNDEFINED) {
      column_types[0] = flex_type_enum::STRING;
    }
    column_names[0] = "X1";
  } 
}