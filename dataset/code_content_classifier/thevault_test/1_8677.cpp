bool CMICmdCmdTargetDetach::Execute() {
  CMICmnLLDBDebugSessionInfo &rSessionInfo(
      CMICmnLLDBDebugSessionInfo::Instance());

  lldb::SBProcess process = rSessionInfo.GetProcess();

  if (!process.IsValid()) {
    SetError(CMIUtilString::Format(MIRSRC(IDS_CMD_ERR_INVALID_PROCESS),
                                   m_cmdData.strMiCmd.c_str()));
    return MIstatus::failure;
  }

  process.Detach();

  return MIstatus::success;
}