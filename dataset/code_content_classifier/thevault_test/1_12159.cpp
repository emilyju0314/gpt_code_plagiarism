void AttachmentsWindow::RemoveTableItems(const QList<QTableWidgetItem*>& items)
    {
        // import and start playing the animation
        AZStd::string outResult;
        MCore::CommandGroup group(AZStd::string("Remove Attachment Actor").c_str());

        // iterate trough all selected items
        for (const QTableWidgetItem* item : items)
        {
            if (item == nullptr || item->column() != 1)
            {
                continue;
            }

            // the attachment id
            const int id                    = GetIDFromTableRow(item->row());
            const AZStd::string nodeName    = GetNodeNameFromTableRow(item->row());

            group.AddCommandString(AZStd::string::format("RemoveAttachment -attachmentID %d -attachToID %i -attachToNode \"%s\"", id, m_actorInstance->GetID(), nodeName.c_str()).c_str());
        }

        // execute the group command
        GetCommandManager()->ExecuteCommandGroup(group, outResult);

        // Reinit the table
        ReInit();
    }