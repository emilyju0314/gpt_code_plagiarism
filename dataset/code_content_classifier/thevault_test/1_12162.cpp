void AttachmentsWindow::OnSelectNodeButtonClicked()
    {
        // get the sender widget
        QLabel* widget = (QLabel*)(QWidget*)sender();
        if (widget == nullptr)
        {
            return;
        }

        // select the clicked row
        const int row = GetRowContainingWidget(widget);
        if (row != -1)
        {
            m_tableWidget->selectRow(row);
        }

        m_nodeBeforeSelectionWindow = GetSelectedNodeName();

        // show the node selection window
        m_nodeSelectionWindow->Update(m_actorInstance->GetID());
        m_nodeSelectionWindow->show();
    }