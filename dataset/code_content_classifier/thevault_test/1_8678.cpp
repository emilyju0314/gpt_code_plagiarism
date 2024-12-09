bool CMICmdBase::HandleSBError(const lldb::SBError &error,
                               const std::function<bool()> &successHandler,
                               const std::function<void()> &errorHandler) {
  if (error.Success())
    return successHandler();

  SetError(error.GetCString());
  errorHandler();
  return MIstatus::failure;
}