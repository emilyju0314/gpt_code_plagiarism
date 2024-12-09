bool TimeViewPlugin::Init()
    {
        m_commandCallbacks.emplace_back(new CommandAdjustMotionCallback(false));
        GetCommandManager()->RegisterCommandCallback("AdjustMotion", m_commandCallbacks.back());

        m_commandCallbacks.emplace_back(new CommandSelectCallback(false));
        GetCommandManager()->RegisterCommandCallback("Select", m_commandCallbacks.back());

        m_commandCallbacks.emplace_back(new CommandUnselectCallback(false));
        GetCommandManager()->RegisterCommandCallback("Unselect", m_commandCallbacks.back());

        m_commandCallbacks.emplace_back(new CommandClearSelectionCallback(false));
        GetCommandManager()->RegisterCommandCallback("ClearSelection", m_commandCallbacks.back());

        m_commandCallbacks.emplace_back(new CommandRecorderClearCallback(false));
        GetCommandManager()->RegisterCommandCallback("RecorderClear", m_commandCallbacks.back());

        m_commandCallbacks.emplace_back(new UpdateInterfaceCallback(false));
        GetCommandManager()->RegisterCommandCallback("AdjustDefaultPlayBackInfo", m_commandCallbacks.back());

        m_commandCallbacks.emplace_back(new UpdateInterfaceCallback(false));
        GetCommandManager()->RegisterCommandCallback("PlayMotion", m_commandCallbacks.back());

        // load the cursors
        m_zoomInCursor = new QCursor(QPixmap(QDir{ QString(MysticQt::GetDataDir().c_str()) }.filePath("Images/Rendering/ZoomInCursor.png")).scaled(32, 32));
        m_zoomOutCursor = new QCursor(QPixmap(QDir{ QString(MysticQt::GetDataDir().c_str()) }.filePath("Images/Rendering/ZoomOutCursor.png")).scaled(32, 32));

        // create main widget
        m_mainWidget = new QWidget(m_dock);
        m_dock->setWidget(m_mainWidget);
        QGridLayout* mainLayout = new QGridLayout();
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        m_mainWidget->setLayout(mainLayout);

        // create widgets in the header
        QHBoxLayout* topLayout = new QHBoxLayout();
        // Top
        m_timeViewToolBar = new TimeViewToolBar(this);

        // Top-left
        m_timeInfoWidget = new TimeInfoWidget(this);
        m_timeInfoWidget->setFixedWidth(175);
        topLayout->addWidget(m_timeInfoWidget);
        topLayout->addWidget(m_timeViewToolBar);
        mainLayout->addLayout(topLayout, 0, 0, 1, 2);

        // Top-right
        m_trackDataHeaderWidget = new TrackDataHeaderWidget(this, m_dock);
        m_trackDataHeaderWidget->setFixedHeight(40);

        // create widgets in the body. For the body we are going to put a scroll area
        // so we can get a vertical scroll bar when we have more tracks than what the
        // view can show
        QScrollArea* bodyWidget = new QScrollArea(m_mainWidget);
        bodyWidget->setFrameShape(QFrame::NoFrame);
        bodyWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bodyWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        bodyWidget->setWidgetResizable(true);

        // scroll areas require an inner widget to hold the layout (instead of a layout directly).
        QWidget* innerWidget = new QWidget(bodyWidget);
        QHBoxLayout* bodyLayout = new QHBoxLayout();
        bodyLayout->setMargin(0);
        bodyLayout->setSpacing(0);
        innerWidget->setLayout(bodyLayout);
        bodyWidget->setWidget(innerWidget);
        mainLayout->addWidget(bodyWidget, 2, 0, 1, 2);

        // Bottom-left
        m_trackHeaderWidget = new TrackHeaderWidget(this, m_dock);
        m_trackHeaderWidget->setFixedWidth(175);
        bodyLayout->addWidget(m_trackHeaderWidget);

        // Left
        QHBoxLayout* addTrackAndTrackDataLayout = new QHBoxLayout;
        addTrackAndTrackDataLayout->addWidget(m_trackHeaderWidget->GetAddTrackWidget());
        m_trackHeaderWidget->GetAddTrackWidget()->setFixedWidth(175);
        addTrackAndTrackDataLayout->addWidget(m_trackDataHeaderWidget);

        mainLayout->addLayout(addTrackAndTrackDataLayout, 1, 0, 1, 2);

        // bottom-right
        m_trackDataWidget = new TrackDataWidget(this, m_dock);
        bodyLayout->addWidget(m_trackDataWidget);

        connect(m_trackDataWidget, &TrackDataWidget::SelectionChanged, this, &TimeViewPlugin::OnSelectionChanged);

        connect(m_trackDataWidget, &TrackDataWidget::ElementTrackChanged, this, &TimeViewPlugin::MotionEventTrackChanged);
        connect(m_trackDataWidget, &TrackDataWidget::MotionEventChanged, this, &TimeViewPlugin::MotionEventChanged);
        connect(this, &TimeViewPlugin::DeleteKeyPressed, this, &TimeViewPlugin::RemoveSelectedMotionEvents);
        connect(m_dock, &QDockWidget::visibilityChanged, this, &TimeViewPlugin::VisibilityChanged);

        connect(this, &TimeViewPlugin::ManualTimeChange, this, &TimeViewPlugin::OnManualTimeChange);

        connect(m_timeViewToolBar, &TimeViewToolBar::RecorderStateChanged, this, &TimeViewPlugin::RecorderStateChanged);

        SetCurrentTime(0.0f);
        SetScale(1.0f);

        SetRedrawFlag();

        m_timeViewToolBar->UpdateInterface();

        EMotionFX::AnimGraphEditorNotificationBus::Handler::BusConnect();
        return true;
    }