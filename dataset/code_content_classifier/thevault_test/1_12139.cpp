void ActionHistoryCallback::OnPreExecuteCommandGroup(MCore::CommandGroup* group, bool undo)
    {
        if (!m_groupExecuting && group->GetNumCommands() > 64)
        {
            m_groupExecuting = true;
            m_executedGroup = group;
            m_currentCommandIndex = 0;
            m_numGroupCommands = group->GetNumCommands();

            GetManager()->SetAvoidRendering(true);

            EMotionFX::GetEventManager().OnProgressStart();

            m_tempString = AZStd::string::format("%s%s", undo ? "Undo: " : "", group->GetGroupName());
            EMotionFX::GetEventManager().OnProgressText(m_tempString.c_str());
        }

        if (group && MCore::GetLogManager().GetLogLevels() & MCore::LogCallback::LOGLEVEL_DEBUG)
        {
            m_tempString = AZStd::string::format("Starting %s of command group '%s'", undo ? "undo" : "execution", group->GetGroupName());
            MCore::LogDebugMsg(m_tempString.c_str());
        }
    }