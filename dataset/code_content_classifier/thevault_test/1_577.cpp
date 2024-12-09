void cin_proc() {
  while (proc_running) {
    std::string line;
    std::getline(std::cin, line);

    size_t delim = line.find(' ');
    if (line.substr(0, delim) != "send") {
      MY_ERROR_STREAM << "warning: support only send operation" << std::endl;
      continue;
    }
    std::string message = line.substr(delim+1, line.size()-delim);
    grab_lock(msglock);
    messages.push(message);
    release_lock(msglock);
  }
}