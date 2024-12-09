bool NodeGroupsPlugin::Init()
    {
        // create the dialog stack
        assert(m_dialogStack == nullptr);
        m_dialogStack = new MysticQt::DialogStack();
        m_dock->setMinimumWidth(300);
        m_dock->setMinimumHeight(100);
        m_dock->setWidget(m_dialogStack);

        // create the management and node group widgets
        m_nodeGroupWidget            = new NodeGroupWidget();
        m_nodeGroupManagementWidget  = new NodeGroupManagementWidget(m_nodeGroupWidget);

        // add the widgets to the dialog stack
        m_dialogStack->Add(m_nodeGroupManagementWidget, "Node Group Management", false, true, true, false);
        m_dialogStack->Add(m_nodeGroupWidget, "Node Group", false, true, true);

        // create and register the command callbacks only (only execute this code once for all plugins)
        m_selectCallback             = new CommandSelectCallback(false);
        m_unselectCallback           = new CommandUnselectCallback(false);
        m_clearSelectionCallback     = new CommandClearSelectionCallback(false);
        m_adjustNodeGroupCallback    = new CommandAdjustNodeGroupCallback(false);
        m_addNodeGroupCallback       = new CommandAddNodeGroupCallback(false);
        m_removeNodeGroupCallback    = new CommandRemoveNodeGroupCallback(false);

        GetCommandManager()->RegisterCommandCallback("Select", m_selectCallback);
        GetCommandManager()->RegisterCommandCallback("Unselect", m_unselectCallback);
        GetCommandManager()->RegisterCommandCallback("ClearSelection", m_clearSelectionCallback);
        GetCommandManager()->RegisterCommandCallback(CommandSystem::CommandAdjustNodeGroup::s_commandName.data(), m_adjustNodeGroupCallback);
        GetCommandManager()->RegisterCommandCallback("AddNodeGroup", m_addNodeGroupCallback);
        GetCommandManager()->RegisterCommandCallback("RemoveNodeGroup", m_removeNodeGroupCallback);

        // reinit the dialog
        ReInit();

        // connect the window activation signal to refresh if reactivated
        connect(m_dock, &QDockWidget::visibilityChanged, this, &NodeGroupsPlugin::WindowReInit);

        return true;
    }