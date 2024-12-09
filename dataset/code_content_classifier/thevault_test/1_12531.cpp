void KeyboardShortcutsWindow::OnAssignNewKey()
    {
        if (m_contextMenuAction == nullptr)
        {
            return;
        }

        // assign the new shortcut
        OnShortcutChange(m_contextMenuActionIndex, 0);
    }