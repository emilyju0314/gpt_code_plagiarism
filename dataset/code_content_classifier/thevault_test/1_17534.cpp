void signal_callback_handler(int signum) {
  std::cout << "Caught interrupt " << signum << ". Proteus is ending..."
            << std::endl;
#ifdef PROTEUS_ENABLE_HTTP
  proteus::http::stop();
#endif
}