void usage([[maybe_unused]] AZ::Test::Platform& platform)
    {
        std::stringstream ss;
        ss <<
            "AzTestRunner\n"
            "Runs AZ tests. Exit code is the result from GoogleTest.\n"
            "\n"
            "Usage:\n"
            "   AzTestRunner.exe <lib> (AzRunUnitTests|AzRunBenchmarks) [--wait-for-debugger] [--pause-on-completion] [google-test-args]\n"
            "\n"
            "Options:\n"
            "   <lib>: the module to test\n"
            "   <hook>: the name of the aztest hook function to run in the <lib>\n"
            "           'AzRunUnitTests' will hook into unit tests\n"
            "           'AzRunBenchmarks' will hook into benchmark tests\n"
            "   --wait-for-debugger: tells runner to wait for debugger to attach to process (on supported platforms)\n"
            "   --pause-on-completion: tells the runner to pause after running the tests\n"
            "   --quiet: disables stdout for minimal output while running tests\n"
            "\n"
            "Example:\n"
            "   AzTestRunner.exe AzCore.Tests.dll AzRunUnitTests --pause-on-completion\n"
            "\n"
            "Exit Codes:\n"
            "   0 - all tests pass\n"
            "   1 - test failure\n"
            << "   " << INCORRECT_USAGE << " - incorrect usage (see above)\n"
            << "   " << LIB_NOT_FOUND << " - library/dll could not be loaded\n"
            << "   " << SYMBOL_NOT_FOUND << " - export symbol not found\n";

        std::cerr << ss.str() << std::endl;
    }