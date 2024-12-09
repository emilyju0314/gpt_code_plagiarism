void ActionHistoryPlugin::OnSelectedItemChanged()
    {
        // Get the list of selected items and make sure exactly one is selected.
        QList<QListWidgetItem*> selected = m_list->selectedItems();
        if (selected.count() != 1)
        {
            return;
        }

        // Get the selected item and its index (row number in the list).
        const uint32 index = m_list->row(selected.at(0));

        // Change the command index.
        m_callback->OnSetCurrentCommand(index);
    }