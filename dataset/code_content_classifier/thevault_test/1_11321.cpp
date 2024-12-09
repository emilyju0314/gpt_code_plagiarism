void read_csv_header(csv_info& info,
                     const std::string& path,
                     csv_line_tokenizer& tokenizer,
                     bool use_header,
                     size_t skip_rows) {
  std::string first_line;
  std::vector<std::string> first_line_tokens;
  general_ifstream probe_fin(path);

  if (!probe_fin.good()) {
    log_and_throw("Fail reading " + sanitize_url(path));
  }

  // skip skip_rows lines
  std::string skip_string;
  for (size_t i = 0;i < skip_rows; ++i) {
    eol_getline(probe_fin, skip_string, tokenizer.line_terminator);
  }

  // skip rows with no data
  while (first_line_tokens.size() == 0 && probe_fin.good()) {
    eol_getline(probe_fin, first_line, tokenizer.line_terminator);
    boost::algorithm::trim(first_line);
    tokenizer.tokenize_line(&(first_line[0]), 
                            first_line.length(), 
                            first_line_tokens);
  }

  info.ncols = first_line_tokens.size();
  if (info.ncols == 0) log_and_throw("First line is empty. Invalid CSV File?");

  if (use_header) {
    info.column_names = first_line_tokens;
    make_unique_column_names(info.column_names);
    first_line.clear();
    first_line_tokens.clear();
  } else {
    info.column_names.resize(info.ncols);
    for (size_t i = 0;i < info.ncols; ++i) {
      info.column_names[i] = "X" + std::to_string(i + 1);
    }
    // do not clear first_line and first_line_tokens. They are actual data.
  }
}