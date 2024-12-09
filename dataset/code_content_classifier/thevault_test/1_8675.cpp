bool CMICmdCmdSymbolListLines::Execute() {
  CMICMDBASE_GETOPTION(pArgFile, File, m_constStrArgNameFile);

  const auto &rSessionInfo(CMICmnLLDBDebugSessionInfo::Instance());
  if (rSessionInfo.GetTarget() == rSessionInfo.GetDebugger().GetDummyTarget()) {
    SetError(CMIUtilString::Format(MIRSRC(IDS_CMD_ERR_INVALID_TARGET_CURRENT),
                                   m_cmdData.strMiCmd.c_str()));
    return MIstatus::failure;
  }

  const lldb::SBFileSpec source_file_spec(pArgFile->GetValue().c_str(), true);
  const char *source_file_name = source_file_spec.GetFilename();
  const char *source_file_directory = source_file_spec.GetDirectory();
  const bool has_path = source_file_directory;

  lldb::SBSymbolContextList sc_cu_list =
      CMICmnLLDBDebugSessionInfo::Instance().GetTarget().FindCompileUnits(
          source_file_spec);

  bool found_something = false;
  for (uint32_t i = 0, e = sc_cu_list.GetSize(); i < e; ++i) {
    const lldb::SBCompileUnit cu =
        sc_cu_list.GetContextAtIndex(i).GetCompileUnit();
    for (uint32_t j = 0, e = cu.GetNumLineEntries(); j < e; ++j) {
      const lldb::SBLineEntry line = cu.GetLineEntryAtIndex(j);
      const lldb::SBFileSpec line_spec = line.GetFileSpec();
      if (line_spec.GetFilename() == source_file_name) {
        if (has_path && (line_spec.GetDirectory() != source_file_directory))
          continue;
        // We don't need a line with start address equals to end one,
        // so just skip it.
        const lldb::SBAddress line_start_address = line.GetStartAddress();
        const lldb::SBAddress line_end_address = line.GetEndAddress();
        if (line_start_address == line_end_address)
          continue;
        // We have a matching line.
        found_something = true;
        m_resultList.Add(CreateMITuplePCLine(
            line_start_address.GetFileAddress(), line.GetLine()));
      }
    }
  }
  if (!found_something) {
    SetError(MIRSRC(IDS_UTIL_FILE_ERR_INVALID_PATHNAME));
    return MIstatus::failure;
  }
  return MIstatus::success;
}