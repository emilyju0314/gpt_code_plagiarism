void tst_shortopts_args_missingarg(rtt_dsxx::UnitTest &ut) {
  std::cout << "\n>>> Begin test 8..." << std::endl;

  // Simulate argc and argv for no arguments case.
  std::array<char const *, 2> my_argv = {"tstXGetopt", "-c"};

  // Register options
  try {
    rtt_dsxx::XGetopt program_options(static_cast<int>(my_argv.size()), my_argv.data(), "hvc:");
    FAILMSG("Insist failed to fire with missing required argument.");
  } catch (rtt_dsxx::assertion & /*error*/) {
    PASSMSG("As expected, Insist fired with missing required argument.");
  }
  return;
}