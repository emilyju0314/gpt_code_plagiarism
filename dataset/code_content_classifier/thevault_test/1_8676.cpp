bool CMICmdCmdTargetAttach::Execute() {
  CMICMDBASE_GETOPTION(pArgPid, Number, m_constStrArgPid);
  CMICMDBASE_GETOPTION(pArgFile, OptionShort, m_constStrArgNamedFile);
  CMICMDBASE_GETOPTION(pArgWaitFor, OptionLong, m_constStrArgWaitFor);

  CMICmnLLDBDebugSessionInfo &rSessionInfo(
      CMICmnLLDBDebugSessionInfo::Instance());

  // If the current target is invalid, create one
  lldb::SBTarget target = rSessionInfo.GetTarget();
  if (!target.IsValid()) {
    target = rSessionInfo.GetDebugger().CreateTarget(nullptr);
    if (!target.IsValid()) {
      SetError(CMIUtilString::Format(MIRSRC(IDS_CMD_ERR_INVALID_TARGET_CURRENT),
                                     m_cmdData.strMiCmd.c_str()));
      return MIstatus::failure;
    }
  }

  lldb::SBError error;
  lldb::SBListener listener;
  if (pArgPid->GetFound() && pArgPid->GetValid()) {
    lldb::pid_t pid;
    pid = pArgPid->GetValue();
    target.AttachToProcessWithID(listener, pid, error);
  } else if (pArgFile->GetFound() && pArgFile->GetValid()) {
    bool bWaitFor = (pArgWaitFor->GetFound());
    CMIUtilString file;
    pArgFile->GetExpectedOption<CMICmdArgValString>(file);
    target.AttachToProcessWithName(listener, file.c_str(), bWaitFor, error);
  } else {
    SetError(CMIUtilString::Format(MIRSRC(IDS_CMD_ERR_ATTACH_BAD_ARGS),
                                   m_cmdData.strMiCmd.c_str()));
    return MIstatus::failure;
  }

  lldb::SBStream errMsg;
  if (error.Fail()) {
    SetError(CMIUtilString::Format(MIRSRC(IDS_CMD_ERR_ATTACH_FAILED),
                                   m_cmdData.strMiCmd.c_str(),
                                   errMsg.GetData()));
    return MIstatus::failure;
  }

  return MIstatus::success;
}