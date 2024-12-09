void ShortcutReceiverDialog::ResetToDefault()
    {
        m_key    = m_orgAction->m_defaultKeySequence;

        UpdateInterface();
    }