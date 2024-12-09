void JumpToSafetySignalHandler(
    SignalHandler::HandlerScope scope,
    int signum,
    siginfo_t* siginfo,
    void* ucontext) {
  SignalState& state = *(SignalState*)scope.GetData();

  if (state.tid == threadID() && state.inSection.load()) {
    scope.siglongjmp(state.sigJmpBuf, 1);
  }

  scope.CallPreviousHandler(signum, siginfo, ucontext);
}