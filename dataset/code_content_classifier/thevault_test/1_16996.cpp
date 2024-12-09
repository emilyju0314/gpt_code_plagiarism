std::vector<bool> GetTestParams() {
  if (GetHttp2RestartFlag(http2_parse_priority_update_frame)) {
    return {true};  // Actual Boolean value is ignored.
  } else {
    return {};
  }
}