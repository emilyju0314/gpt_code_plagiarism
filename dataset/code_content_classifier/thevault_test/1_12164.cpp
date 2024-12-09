int AttachmentsWindow::GetIDFromTableRow(int row)
    {
        QTableWidgetItem* item = m_tableWidget->item(row, 1);
        if (item == nullptr)
        {
            return MCore::InvalidIndexT<int>;
        }

        AZStd::string id;
        FromQtString(item->text(), &id);

        return AzFramework::StringFunc::ToInt(id.c_str());
    }