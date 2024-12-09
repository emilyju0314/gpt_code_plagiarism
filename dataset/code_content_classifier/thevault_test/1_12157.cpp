void AttachmentsWindow::OnUpdateButtonsEnabled()
    {
        m_removeButton->setEnabled(m_tableWidget->selectedItems().size() != 0);
        m_clearButton->setEnabled(m_tableWidget->rowCount() != 0);
    }