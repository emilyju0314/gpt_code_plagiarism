void KeyboardShortcutsWindow::OnResetToDefault()
    {
        if (m_contextMenuAction == nullptr)
        {
            return;
        }

        m_contextMenuAction->m_qaction->setShortcut(m_contextMenuAction->m_defaultKeySequence);

        ReInit();
    }