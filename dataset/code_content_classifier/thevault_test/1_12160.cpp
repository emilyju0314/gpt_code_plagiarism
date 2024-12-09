void AttachmentsWindow::OnDroppedAttachmentsActors()
    {
        m_isDeformableAttachment = false;

        // add attachments to the selected actorinstance
        AddAttachments(m_dropFileNames);

        // clear the attachments array
        m_dropFileNames.clear();
    }