bool Mailbox::WriteValueString(const std::string& out_file, const std::string& value_str) {
  bool  rtn = false;
  std::ofstream file;
  std::ofstream tmp_file;
  std::string out_tmp_file = out_file + ".sysmgr_tmp";

  LOG(LS_VERBOSE) << "out_file=" << out_file << " out_tmp_file=" << out_tmp_file;
  tmp_file.open(out_tmp_file.c_str(), std::ios::out | std::ios::trunc);
  if (tmp_file.is_open()) {
    tmp_file << value_str;
    tmp_file.close();
    rename(out_tmp_file.c_str(), out_file.c_str());
    rtn = true;
  } else {
    LOG(LS_ERROR) << "WriteValueString: Failed to open: " << out_file;
  }

  LOG(LS_VERBOSE) << "rtn=" << rtn;
  return rtn;
}