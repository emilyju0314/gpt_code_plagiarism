bool LogWindowPlugin::Init()
    {
        // create the widget
        QWidget* windowWidget = new QWidget(m_dock);

        // create the layout
        QVBoxLayout* windowWidgetLayout = new QVBoxLayout();
        windowWidgetLayout->setSpacing(3);
        windowWidgetLayout->setMargin(3);

        // create the find widget
        m_searchWidget = new AzQtComponents::FilteredSearchWidget(windowWidget);
        AddFilter(tr("Fatal"), MCore::LogCallback::LOGLEVEL_FATAL, true);
        AddFilter(tr("Error"), MCore::LogCallback::LOGLEVEL_ERROR, true);
        AddFilter(tr("Warning"), MCore::LogCallback::LOGLEVEL_WARNING, true);
        AddFilter(tr("Info"), MCore::LogCallback::LOGLEVEL_INFO, true);
    #ifdef MCORE_DEBUG
        AddFilter(tr("Detailed Info"), MCore::LogCallback::LOGLEVEL_DETAILEDINFO, true);
        AddFilter(tr("Debug"), MCore::LogCallback::LOGLEVEL_DEBUG, true);
    #else
        AddFilter(tr("Detailed Info"), MCore::LogCallback::LOGLEVEL_DETAILEDINFO, false);
        AddFilter(tr("Debug"), MCore::LogCallback::LOGLEVEL_DEBUG, false);
    #endif
        connect(m_searchWidget, &AzQtComponents::FilteredSearchWidget::TextFilterChanged, this, &LogWindowPlugin::OnTextFilterChanged);
        connect(m_searchWidget, &AzQtComponents::FilteredSearchWidget::TypeFilterChanged, this, &LogWindowPlugin::OnTypeFilterChanged);

        // create the filter layout
        QHBoxLayout* topLayout = new QHBoxLayout();
        topLayout->addWidget(new QLabel("Filter:"));
        topLayout->addWidget(m_searchWidget);
        topLayout->addStretch();
        topLayout->setSpacing(6);

        // add the filter layout
        windowWidgetLayout->addLayout(topLayout);

        // create and add the table and callback
        m_logCallback = new LogWindowCallback(nullptr);
        windowWidgetLayout->addWidget(m_logCallback);

        // set the layout
        windowWidget->setLayout(windowWidgetLayout);

        // set the table as content
        m_dock->setWidget(windowWidget);

        // create the callback
        m_logCallback->SetLogLevels(MCore::LogCallback::LOGLEVEL_ALL);
        MCore::GetLogManager().AddLogCallback(m_logCallback);

        // return true because the plugin is correctly initialized
        return true;
    }