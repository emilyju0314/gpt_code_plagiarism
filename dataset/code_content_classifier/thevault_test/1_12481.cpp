bool MotionSetsWindowPlugin::Init()
    {
        auto AddCallback = [=](const char* commandName, MCore::Command::Callback* callback)
        {
            m_callbacks.emplace_back(callback);
            GetCommandManager()->RegisterCommandCallback(commandName, m_callbacks.back());
        };

        AddCallback("CreateMotionSet", new CommandReinitCallback(false));
        AddCallback("RemoveMotionSet", new CommandReinitCallback(false));
        AddCallback("RemoveMotion", new CommandReinitCallback(false));
        AddCallback("AdjustMotionSet", new CommandAdjustMotionSetCallback(false));
        AddCallback("MotionSetAddMotion", new CommandMotionSetAddMotionCallback(false));
        AddCallback("MotionSetRemoveMotion", new CommandMotionSetRemoveMotionCallback(false));
        AddCallback("MotionSetAdjustMotion", new CommandMotionSetAdjustMotionCallback(false));
        AddCallback("LoadMotionSet", new CommandLoadMotionSetCallback(false));

        // create the dialog stack
        assert(m_dialogStack == nullptr);
        m_dialogStack = new MysticQt::DialogStack(m_dock);
        m_dock->setWidget(m_dialogStack);

        // connect the window activation signal to refresh if reactivated
        connect(m_dock, &QDockWidget::visibilityChanged, this, &MotionSetsWindowPlugin::WindowReInit);

        // create the set management window
        m_motionSetManagementWindow = new MotionSetManagementWindow(this, m_dialogStack);
        m_motionSetManagementWindow->Init();
        m_dialogStack->Add(m_motionSetManagementWindow, "Motion Set Management", false, true, true, false);

        // create the motion set properties window
        m_motionSetWindow = new MotionSetWindow(this, m_dialogStack);
        m_motionSetWindow->Init();
        m_dialogStack->Add(m_motionSetWindow, "Motion Set", false, true);

        ReInit();
        SetSelectedSet(nullptr);

        // initialize the dirty files callback
        m_dirtyFilesCallback = new SaveDirtyMotionSetFilesCallback(this);
        GetMainWindow()->GetDirtyFileManager()->AddCallback(m_dirtyFilesCallback);

        return true;
    }