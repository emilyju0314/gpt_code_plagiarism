void KeyboardShortcutsWindow::OnShortcutChange(int row, int column)
    {
        MCORE_UNUSED(column);

        MysticQt::KeyboardShortcutManager* shortcutManager = GetMainWindow()->GetShortcutManager();

        // get access to the group
        MysticQt::KeyboardShortcutManager::Group* group = GetCurrentGroup();

        // get access to the action
        MysticQt::KeyboardShortcutManager::Action* action = group->GetAction(row);

        ShortcutReceiverDialog shortcutWindow(this, action, group);
        m_shortcutReceiverDialog = &shortcutWindow;
        if (shortcutWindow.exec() == QDialog::Accepted)
        {
            // handle conflicts
            if (shortcutWindow.m_conflictDetected)
            {
                shortcutWindow.m_conflictAction->m_qaction->setShortcut({});
            }

            // adjust the shortcut action
            action->m_qaction->setShortcut(shortcutWindow.m_key);

            // save the new shortcuts
            QSettings settings(FromStdString(AZStd::string(GetManager()->GetAppDataFolder() + "EMStudioKeyboardShortcuts.cfg")), QSettings::IniFormat, this);
            shortcutManager->Save(&settings);

            // reinit the window
            ReInit();
        }
        m_shortcutReceiverDialog = nullptr;
    }