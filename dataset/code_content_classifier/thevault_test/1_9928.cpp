static inline void displayWarning(std::string &Msg,
                                  const CallInst *CI,
                                  const Function *F) {
  assert(CI && "Invalid arguments");

  // Note: it may be possible for us to not have a called function, for example
  // if we call a function using a function pointer
  const Function *CurF = CI->getParent()->getParent();
  if(F && F->hasName()) {
    Msg += " across call to ";
    Msg += F->getName();
  }
  DiagnosticInfoOptimizationFailure DI(*CurF, CI->getDebugLoc(), Msg);
  CurF->getContext().diagnose(DI);
}