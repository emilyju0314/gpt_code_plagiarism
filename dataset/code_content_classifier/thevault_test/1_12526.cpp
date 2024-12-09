void KeyboardShortcutsWindow::OnGroupSelectionChanged()
    {
        // get the group index
        m_selectedGroup = m_listWidget->currentRow();
        if (m_selectedGroup == -1)
        {
            return;
        }

        // clear the table
        m_tableWidget->clear();

        // set header item for the table
        m_tableWidget->setColumnCount(2);

        QTableWidgetItem* headerItem = new QTableWidgetItem("Action");
        headerItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        m_tableWidget->setHorizontalHeaderItem(0, headerItem);

        headerItem = new QTableWidgetItem("Shortcut");
        headerItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        m_tableWidget->setHorizontalHeaderItem(1, headerItem);

        // set the vertical header not visible
        QHeaderView* verticalHeader = m_tableWidget->verticalHeader();
        verticalHeader->setVisible(false);

        // get access to the shortcut group and some data
        MysticQt::KeyboardShortcutManager*          shortcutManager = GetMainWindow()->GetShortcutManager();
        MysticQt::KeyboardShortcutManager::Group*   group           = shortcutManager->GetGroup(m_selectedGroup);
        const size_t                                numActions      = group->GetNumActions();

        // set the row count
        m_tableWidget->setRowCount(aznumeric_caster(numActions));

        // fill the table with the media root folders
        for (uint32 i = 0; i < numActions; ++i)
        {
            // get the shortcut action
            MysticQt::KeyboardShortcutManager::Action* action = group->GetAction(i);

            // add the item to the table and set the row height
            QTableWidgetItem* item = new QTableWidgetItem(action->m_qaction->text());
            item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            m_tableWidget->setItem(i, 0, item);

            const QString keyText = ConstructStringFromShortcut(action->m_qaction->shortcut());

            item = new QTableWidgetItem(keyText);
            item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            m_tableWidget->setItem(i, 1, item);

            m_tableWidget->setRowHeight(i, 21);
        }

        // resize the first column
        m_tableWidget->resizeColumnToContents(0);

        // needed to have the last column stretching correctly
        m_tableWidget->setColumnWidth(1, 0);

        // set the last column to take the whole space
        m_tableWidget->horizontalHeader()->setStretchLastSection(true);
    }