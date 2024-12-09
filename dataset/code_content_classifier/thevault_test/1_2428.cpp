void Text_Token_Stream::push_include(std::string &file_name) {
  lines_.push(line_);
  line_ = 1;
  buffers_.push(buffer_);
  buffer_.clear();

  // Now find the absolute path of the file name.

  if (!rtt_dsxx::fileExists(file_name)) {
    // File name as given does not resolve to an existing file. Assume this
    // is a relative path and look for the file in DRACO_INCLUDE_PATH.

    // At present, DRACO_INCLUDE_PATH can contain only a single path.
    // Multiple search options may be implemented in the future.
    auto path = getenv("DRACO_INCLUDE_PATH");
    if (path != nullptr) {
      // For now, the only other possibility:
      file_name = path + ('/' + file_name);
      // If this doesn't exist, the stream will report the error later on.
    }
    // else return and let the stream report the error
  }
  // else the file name as given resolves to an existing file

  Require(check_class_invariants());
  Require(line() == 1);
}