void KeyboardShortcutsWindow::contextMenuEvent(QContextMenuEvent* event)
    {
        // find the table widget item at the clicked position
        QTableWidgetItem* clickedItem = m_tableWidget->itemAt(m_tableWidget->viewport()->mapFromGlobal(event->globalPos()));
        if (clickedItem == nullptr)
        {
            return;
        }

        int actionIndex = clickedItem->row();

        // get access to the group
        MysticQt::KeyboardShortcutManager::Group* group = GetCurrentGroup();

        // get access to the action
        m_contextMenuAction      = group->GetAction(actionIndex);
        m_contextMenuActionIndex = actionIndex;

        // create the context menu
        QMenu menu(this);

        QAction* defaultAction = menu.addAction("Reset To Default");
        connect(defaultAction, &QAction::triggered, this, &KeyboardShortcutsWindow::OnResetToDefault);

        QAction* newKeyAction = menu.addAction("Assign New Key");
        connect(newKeyAction, &QAction::triggered, this, &KeyboardShortcutsWindow::OnAssignNewKey);

        // show the menu at the given position
        menu.exec(event->globalPos());
    }