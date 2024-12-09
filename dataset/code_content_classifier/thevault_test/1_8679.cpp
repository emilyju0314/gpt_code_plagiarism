bool CMICmdBase::HandleSBErrorWithFailure(
    const lldb::SBError &error, const std::function<void()> &errorHandler) {
  return HandleSBError(
      error, [] { return MIstatus::success; }, errorHandler);
}