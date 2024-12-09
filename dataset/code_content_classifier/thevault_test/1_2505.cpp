void tst_lopts_args_missingarg(rtt_dsxx::UnitTest &ut) {
  std::cout << "\n>>> Begin test 18..." << std::endl;

  // Simulate argc and argv for no arguments case.
  std::array<char const *, 2> my_argv = {"tstXGetopt", "--create"};

  // Register options
  try {
    rtt_dsxx::XGetopt::csmap long_options = {{'c', "create:"}, {'h', "help"}, {'v', "version"}};

    rtt_dsxx::XGetopt program_options(static_cast<int>(my_argv.size()), my_argv.data(),
                                      long_options);

    FAILMSG("Insist failed to fire with missing required argument.");
  } catch (rtt_dsxx::assertion & /*error*/) {
    PASSMSG("As expected, Insist fired with missing required argument.");
  }
  return;
}