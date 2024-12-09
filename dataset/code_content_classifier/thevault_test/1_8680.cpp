bool CMICmdBase::ParseValidateCmdOptions() {
  CMICmdArgContext argCntxt(m_cmdData.strMiCmdOption);
  if (m_setCmdArgs.Validate(m_cmdData.strMiCmd, argCntxt))
    return MIstatus::success;

  SetError(CMIUtilString::Format(MIRSRC(IDS_CMD_ERR_ARGS),
                                 m_cmdData.strMiCmd.c_str(),
                                 m_setCmdArgs.GetErrorDescription().c_str()));

  return MIstatus::failure;
}