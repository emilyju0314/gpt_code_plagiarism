int AttachmentsWindow::GetRowContainingWidget(const QWidget* widget)
    {
        // loop trough the table items and search for widget
        const int numRows = m_tableWidget->rowCount();
        const int numCols = m_tableWidget->columnCount();
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                if (m_tableWidget->cellWidget(i, j) == widget)
                {
                    return i;
                }
            }
        }

        return -1;
    }