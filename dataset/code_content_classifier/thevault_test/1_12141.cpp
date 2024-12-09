void ActionHistoryCallback::OnAddCommandToHistory(size_t historyIndex, MCore::CommandGroup* group, MCore::Command* command, const MCore::CommandLine& commandLine)
    {
        MCORE_UNUSED(commandLine);
        m_tempString = MCore::CommandManager::CommandHistoryEntry::ToString(group, command, m_index++).c_str();

        m_list->insertItem(aznumeric_caster(historyIndex), new QListWidgetItem(m_tempString.c_str(), m_list));
        m_list->setCurrentRow(aznumeric_caster(historyIndex));
    }