std::string unity_server::parse_server_address(std::string server_address) {
  namespace fs = boost::filesystem;
  // Prevent multiple server listen on the same ipc device.
  if (boost::starts_with(server_address, "ipc://") &&
      fs::exists(fs::path(server_address.substr(6)))) {
    logstream(LOG_FATAL) << "Cannot start graphlab server at " 
                         << server_address<< ". File already exists" << "\n";
    exit(-1);
  }
  // Form default server address using process_id and client's timestamp:
  // ipc://graphlab_server-$pid-$timestamp
  if (boost::starts_with(server_address, "default")) {
    std::string path = "/tmp/graphlab_server-" + std::to_string(getpid());
    { // parse server address: "default-$timestamp"
      // append timestamp to the address
      std::vector<std::string> _tmp;
      boost::split(_tmp, server_address, boost::is_any_of("-"));
      if (_tmp.size() == 2)
        path += "-" + _tmp[1];
    }
    server_address = "ipc://" + path;
    if (fs::exists(fs::path(path))) {
      // It could be a leftover of a previous crashed process, try to delete the file
      if (remove(path.c_str()) != 0) {
        logstream(LOG_FATAL) << "Cannot start graphlab server at "
                             << server_address 
                             << ". File already exists, and cannot be deleted." << "\n";
        exit(-1);
      }
    }
  }
  return server_address;
}