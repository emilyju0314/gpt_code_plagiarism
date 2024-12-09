static bool findXcodeClangPath(llvm::SmallVectorImpl<char> &path) {
  assert(path.empty());

  auto xcrunPath = llvm::sys::findProgramByName("xcrun");
  if (!xcrunPath.getError()) {
    const char *args[] = {"-f", "clang", nullptr};
    sys::TaskQueue queue;
    queue.addTask(xcrunPath->c_str(), args, /*Env=*/llvm::None,
                  /*Context=*/nullptr,
                  /*SeparateErrors=*/true);
    queue.execute(nullptr, [&path](sys::ProcessId PID, int returnCode,
                                   StringRef output, StringRef errors,
                                   void *unused) -> sys::TaskFinishedResponse {
      if (returnCode == 0) {
        output = output.rtrim();
        path.append(output.begin(), output.end());
      }
      return sys::TaskFinishedResponse::ContinueExecution;
    });
  }

  return !path.empty();
}