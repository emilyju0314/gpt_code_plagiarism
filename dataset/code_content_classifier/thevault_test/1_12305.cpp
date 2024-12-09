bool MorphTargetsWindowPlugin::Init()
    {
        // create the static text layout
        m_staticTextWidget = new QWidget();
        m_staticTextLayout = new QVBoxLayout();
        m_staticTextWidget->setLayout(m_staticTextLayout);
        QLabel* label = new QLabel("No morph targets to show.");
        m_staticTextLayout->addWidget(label);
        m_staticTextLayout->setAlignment(label, Qt::AlignCenter);

        // create the dialog stack
        assert(m_dialogStack == nullptr);
        m_dialogStack = new MysticQt::DialogStack();
        m_dock->setMinimumWidth(300);
        m_dock->setMinimumHeight(100);
        m_dock->setWidget(m_staticTextWidget);

        GetCommandManager()->RegisterCommandCallback<CommandSelectCallback>("Select", m_callbacks, false);
        GetCommandManager()->RegisterCommandCallback<CommandUnselectCallback>("Unselect", m_callbacks, false);
        GetCommandManager()->RegisterCommandCallback<CommandClearSelectionCallback>("ClearSelection", m_callbacks, false);
        GetCommandManager()->RegisterCommandCallback<CommandAdjustMorphTargetCallback>("AdjustMorphTarget", m_callbacks, false);
        GetCommandManager()->RegisterCommandCallback<CommandAdjustActorInstanceCallback>("AdjustActorInstance", m_callbacks, false);

        // reinit the dialog
        ReInit();

        // connect the window activation signal to refresh if reactivated
        connect(m_dock, &QDockWidget::visibilityChanged, this, &MorphTargetsWindowPlugin::WindowReInit);

        // done
        return true;
    }