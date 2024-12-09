void populate_row_buffer(const flexible_type & row, 
                         bool is_dataframe,
                         std::vector<flexible_type> & row_buffer) {
  size_t ncols = 1;

  if (is_dataframe && row.get_type() == flex_type_enum::VECTOR) { 
    const flex_vec & vect = row.get<flex_vec>();
    ncols = vect.size();
    
    for (size_t i = 0;i < ncols; ++i) {
      row_buffer[i] = vect[i];
    }
  } else if (is_dataframe && row.get_type() == flex_type_enum::LIST) { 
    const flex_list & rec = row.get<flex_list>();
    ncols = rec.size();
    for (size_t i = 0; i < ncols; ++i) {
      if (row_buffer[i].get_type() == rec[i].get_type()) {
        // no casting necessary
        row_buffer[i] = rec[i];
      } else if (row_buffer[i].get_type() == flex_type_enum::VECTOR && 
        rec[i].get_type() == flex_type_enum::LIST) {
        // manual conversion necessary. This catches the case not handled by flexible_type
        // since the conversion below may fail.
        flex_vec & out = row_buffer[i].mutable_get<flex_vec>();
        const auto & in = rec[i].get<flex_list>();
        out.resize(in.size());
        for (size_t i = 0;i < in.size(); ++i) out[i] = in[i].to<double>();
      } else {
        row_buffer[i] = rec[i];
      }
    }
    // for (size_t i = 0; i < ncols; ++i) {
    //   if (column_types[i] == flex_type_enum::VECTOR) {
    //     row_buffer[i] = rec[i].get<flex_vec>();
    //   } else {
    //     row_buffer[i] = rec[i];
    //   }
    // }       
  } else if (is_dataframe && row.get_type() == flex_type_enum::DICT) {
    const flex_dict & dict = row.get<flex_dict>();
    ncols = dict.size();
    for (size_t i = 0;i < ncols; ++i) {
      row_buffer[i] = dict[i].second;
    }
  } else { 
    // this is not one of the standard code paths so just stuff into
    // the first column of the row buffer
    row_buffer[0] = row;
  }    
}