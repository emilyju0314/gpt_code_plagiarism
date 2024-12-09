void UKF::Log(std::string message, bool print_newline) {

  if ( debug_mode_ ) {

    // hello, Kitty
    std::cout << message;

    if ( print_newline ) {
      std::cout << endl;
    }
  }
}