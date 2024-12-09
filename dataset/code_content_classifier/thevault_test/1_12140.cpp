void ActionHistoryCallback::OnPostExecuteCommandGroup(MCore::CommandGroup* group, bool wasSuccess)
    {
        if (m_executedGroup == group)
        {
            EMotionFX::GetEventManager().OnProgressEnd();

            m_groupExecuting      = false;
            m_executedGroup       = nullptr;
            m_numGroupCommands    = 0;
            m_currentCommandIndex = 0;

            GetManager()->SetAvoidRendering(false);
        }

        if (group && MCore::GetLogManager().GetLogLevels() & MCore::LogCallback::LOGLEVEL_DEBUG)
        {
            m_tempString = AZStd::string::format("%sExecution of command group '%s' %s", wasSuccess ?  "    " : "*** ", group->GetGroupName(), wasSuccess ? "completed successfully" : " FAILED");
            MCore::LogDebugMsg(m_tempString.c_str());
        }
    }