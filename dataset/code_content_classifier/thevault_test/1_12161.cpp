void AttachmentsWindow::OnDroppedDeformableActors()
    {
        m_isDeformableAttachment = true;

        // add attachments to the selected actorinstance
        AddAttachments(m_dropFileNames);

        // clear the attachments array
        m_dropFileNames.clear();
    }