void ActionHistoryCallback::OnRemoveCommand(size_t historyIndex)
    {
        // Remove the item.
        m_isRemoving = true;
        delete m_list->takeItem(aznumeric_caster(historyIndex));
        m_isRemoving = false;
    }