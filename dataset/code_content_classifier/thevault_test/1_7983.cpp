uint64_t GetTS2MMBufSize(bool isAIETrace)
{
  std::string size_str = isAIETrace ?
                         xrt_core::config::get_aie_trace_buffer_size() :
                         xrt_core::config::get_trace_buffer_size();
  std::smatch pieces_match;
  
  // Default is 1M
  uint64_t bytes = TS2MM_DEF_BUF_SIZE;
  // Regex can parse values like : "1024M" "1G" "8192k"
  const std::regex size_regex("\\s*([0-9]+)\\s*(K|k|M|m|G|g|)\\s*");
  if (std::regex_match(size_str, pieces_match, size_regex)) {
    try {
      if (pieces_match[2] == "K" || pieces_match[2] == "k") {
        bytes = std::stoull(pieces_match[1]) * 1024;
      } else if (pieces_match[2] == "M" || pieces_match[2] == "m") {
        bytes = std::stoull(pieces_match[1]) * 1024 * 1024;
      } else if (pieces_match[2] == "G" || pieces_match[2] == "g") {
        bytes = std::stoull(pieces_match[1]) * 1024 * 1024 * 1024;
      } else {
        bytes = std::stoull(pieces_match[1]);
      }
    } catch (const std::exception& ) {
      // User specified number cannot be parsed
      xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", TS2MM_WARN_MSG_BUFSIZE_DEF);
    }
  } else {
    xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", TS2MM_WARN_MSG_BUFSIZE_DEF);
  }
  if (bytes > TS2MM_MAX_BUF_SIZE) {
    bytes = TS2MM_MAX_BUF_SIZE;
    xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", TS2MM_WARN_MSG_BUFSIZE_BIG);
  }
  if (bytes < TS2MM_MIN_BUF_SIZE) {
    bytes = TS2MM_MIN_BUF_SIZE;
    xrt_core::message::send(xrt_core::message::severity_level::warning, "XRT", TS2MM_WARN_MSG_BUFSIZE_SMALL);
  }
  return bytes;
}