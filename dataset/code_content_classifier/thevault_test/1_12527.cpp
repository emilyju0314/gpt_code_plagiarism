MysticQt::KeyboardShortcutManager::Group* KeyboardShortcutsWindow::GetCurrentGroup() const
    {
        // get access to the group
        int32 groupIndex = m_listWidget->currentRow();
        if (groupIndex == -1)
        {
            return nullptr;
        }

        MysticQt::KeyboardShortcutManager* shortcutManager = GetMainWindow()->GetShortcutManager();
        MysticQt::KeyboardShortcutManager::Group* group = shortcutManager->GetGroup(groupIndex);
        return group;
    }