AZStd::string AttachmentsWindow::GetNodeNameFromTableRow(int row)
    {
        QTableWidgetItem* item = m_tableWidget->item(row, 4);
        if (item == nullptr)
        {
            return {};
        }

        return FromQtString(item->whatsThis());
    }