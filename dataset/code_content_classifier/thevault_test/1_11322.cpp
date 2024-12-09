void parse_csv_to_sframe(
    const std::string& path,
    csv_line_tokenizer& tokenizer,
    csv_file_handling_options options,
    sframe& frame,
    std::string frame_sidx_file,
    parallel_csv_parser& parser,
    std::map<std::string, std::shared_ptr<sarray<flexible_type>>>& errors) {
  auto use_header = options.use_header;
  auto continue_on_failure = options.continue_on_failure;
  auto store_errors = options.store_errors;
  auto skip_rows = options.skip_rows;

  logstream(LOG_INFO) << "Loading sframe from " << sanitize_url(path) << std::endl;

  // load; For each line, insert into the frame
  {
    general_ifstream fin(path);
    if (!fin.good()) log_and_throw("Cannot open " + sanitize_url(path));

    // skip skip_rows lines
    std::string skip_string;
    for (size_t i = 0;i < skip_rows; ++i) {
      eol_getline(fin, skip_string, tokenizer.line_terminator);
    }

    // if use_header, we keep throwing away empty or comment lines until we 
    // get one good line
    if (use_header) {
      std::vector<std::string> first_line_tokens;
      // skip rows with no data, and skip the head
      while (first_line_tokens.size() == 0 && fin.good()) {
        std::string line;
        eol_getline(fin, line, tokenizer.line_terminator);
        tokenizer.tokenize_line(&(line[0]), line.length(), first_line_tokens);
      }
      // if we are going to store errors, we don't do early skippng on 
      // mismatched files
      if (!store_errors && 
          first_line_tokens.size() != parser.num_input_columns()) {
        logprogress_stream << "Unexpected number of columns found in " << path
                           << ". Skipping this file." << std::endl;
        return;
      }
    }
    
    // store errors for this particular file in an sarray
    auto file_errors = std::make_shared<sarray<flexible_type>>();
    if (store_errors) {
      file_errors->open_for_write();
      file_errors->set_type(flex_type_enum::STRING);
    }

    try {
      parser.parse(fin, frame, *file_errors);
    } catch(const std::string& s) {
      frame.close();
      if (store_errors) file_errors->close();
      log_and_throw(s);
    }

    if (continue_on_failure && parser.num_lines_failed() > 0) {
      logprogress_stream << parser.num_lines_failed() 
                         << " lines failed to parse correctly" 
                         << std::endl;
    }

    if (store_errors) {
      file_errors->close();
      if (file_errors->size() > 0) {
        errors.insert(std::make_pair(path, file_errors));
      }
    }

    logprogress_stream << "Finished parsing file " << sanitize_url(path) << std::endl;
  }
}