static void validateCommandLine(StringRef BinaryPath,
                                cl::list<std::string> &PerfTraceFilenames) {
  // Allow the invalid perfscript if we only use to show binary disassembly.
  if (!ShowDisassemblyOnly) {
    for (auto &File : PerfTraceFilenames) {
      if (!llvm::sys::fs::exists(File)) {
        std::string Msg = "Input perf script(" + File + ") doesn't exist!";
        exitWithError(Msg);
      }
    }
  }

  if (!llvm::sys::fs::exists(BinaryPath)) {
    std::string Msg = "Input binary(" + BinaryPath.str() + ") doesn't exist!";
    exitWithError(Msg);
  }

  if (CSProfileGenerator::MaxCompressionSize < -1) {
    exitWithError("Value of --compress-recursion should >= -1");
  }
  if (ShowSourceLocations && !ShowDisassemblyOnly) {
    exitWithError("--show-source-locations should work together with "
                  "--show-disassembly-only!");
  }
}