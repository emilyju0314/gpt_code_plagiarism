void ask_mode() {
  std::cout << "Select mode encrypt[enc] / decrypt[dec]: ";
  std::getline(std::cin, mode);

  if (mode != "enc" && mode != "dec") {
    std::cout << "Select a valid mode." << std::endl;
    ask_mode();
  }

  if (mode == "dec") {
    reverse(symbols.begin(), symbols.end());
  }

  return;
}