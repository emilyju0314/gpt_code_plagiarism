bool AttachmentsPlugin::Init()
    {
        //LogInfo("Initializing attachments window.");

        // create the dialog stack
        assert(m_dialogStack == nullptr);
        m_dialogStack = new MysticQt::DialogStack(m_dock);
        m_dock->setWidget(m_dialogStack);

        // create the attachments window
        m_attachmentsWindow = new AttachmentsWindow(m_dialogStack);
        m_attachmentsWindow->Init();
        m_dialogStack->Add(m_attachmentsWindow, "Selected Actor Instance", false, true, true, false);

        // create the attachment hierarchy window
        m_attachmentsHierarchyWindow = new AttachmentsHierarchyWindow(m_dialogStack);
        m_attachmentsHierarchyWindow->Init();
        m_dialogStack->Add(m_attachmentsHierarchyWindow, "Hierarchy", false, true, true, false);

        // create the attachment nodes window
        m_attachmentNodesWindow = new AttachmentNodesWindow(m_dialogStack);
        m_dialogStack->Add(m_attachmentNodesWindow, "Attachment Nodes", false, true);

        // create and register the command callbacks only (only execute this code once for all plugins)
        m_selectCallback                     = new CommandSelectCallback(false);
        m_unselectCallback                   = new CommandUnselectCallback(false);
        m_clearSelectionCallback             = new CommandClearSelectionCallback(false);

        m_addAttachmentCallback              = new CommandAddAttachmentCallback(false);
        m_addDeformableAttachmentCallback    = new CommandAddDeformableAttachmentCallback(false);
        m_removeAttachmentCallback           = new CommandRemoveAttachmentCallback(false);
        m_clearAttachmentsCallback           = new CommandClearAttachmentsCallback(false);
        m_adjustActorCallback                = new CommandAdjustActorCallback(false);
        m_removeActorInstanceCallback        = new CommandRemoveActorInstanceCallback(false);

        GetCommandManager()->RegisterCommandCallback("Select", m_selectCallback);
        GetCommandManager()->RegisterCommandCallback("Unselect", m_unselectCallback);
        GetCommandManager()->RegisterCommandCallback("ClearSelection", m_clearSelectionCallback);

        GetCommandManager()->RegisterCommandCallback("AddAttachment", m_addAttachmentCallback);
        GetCommandManager()->RegisterCommandCallback("AddDeformableAttachment", m_addDeformableAttachmentCallback);
        GetCommandManager()->RegisterCommandCallback("RemoveAttachment", m_removeAttachmentCallback);
        GetCommandManager()->RegisterCommandCallback("ClearAttachments", m_clearAttachmentsCallback);
        GetCommandManager()->RegisterCommandCallback("AdjustActor", m_adjustActorCallback);
        GetCommandManager()->RegisterCommandCallback("RemoveActorInstance", m_removeActorInstanceCallback);

        // reinit the dialog
        ReInit();

        // connect the window activation signal to refresh if reactivated
        connect(m_dock, &QDockWidget::visibilityChanged, this, &AttachmentsPlugin::WindowReInit);

        return true;
    }