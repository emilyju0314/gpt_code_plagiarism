void intepreter() {
  std::string msg;
  while (proc_running) {
    std::cout << ">>> " << std::flush;
    getline(std::cin, msg);
    if (msg.empty())
      continue;
    usercmd = msg;
    userevent = true;
  }
  std::cout << "client_talk finished cleanly" << std::endl;
}