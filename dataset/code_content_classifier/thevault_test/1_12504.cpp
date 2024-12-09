bool MotionEventsPlugin::Init()
    {
        GetEventPresetManager()->LoadFromSettings();
        GetEventPresetManager()->Load();

        // create callbacks
        m_adjustMotionCallback = new CommandAdjustMotionCallback(false);
        m_selectCallback = new CommandSelectCallback(false);
        m_unselectCallback = new CommandUnselectCallback(false);
        m_clearSelectionCallback = new CommandClearSelectionCallback(false);
        GetCommandManager()->RegisterCommandCallback("AdjustMotion", m_adjustMotionCallback);
        GetCommandManager()->RegisterCommandCallback("Select", m_selectCallback);
        GetCommandManager()->RegisterCommandCallback("Unselect", m_unselectCallback);
        GetCommandManager()->RegisterCommandCallback("ClearSelection", m_clearSelectionCallback);

        // create the dialog stack
        assert(m_dialogStack == nullptr);
        m_dialogStack = new MysticQt::DialogStack(m_dock);
        m_dock->setWidget(m_dialogStack);

        // create the motion event presets widget
        m_motionEventPresetsWidget = new MotionEventPresetsWidget(m_dialogStack, this);
        m_dialogStack->Add(m_motionEventPresetsWidget, "Motion Event Presets", false, true);
        connect(m_dock, &QDockWidget::visibilityChanged, this, &MotionEventsPlugin::WindowReInit);

        // create the motion event properties widget
        m_motionEventWidget = new MotionEventWidget(m_dialogStack);
        m_dialogStack->Add(m_motionEventWidget, "Motion Event Properties", false, true);

        ValidatePluginLinks();
        UpdateMotionEventWidget();

        return true;
    }