bool ActionHistoryPlugin::Init()
    {
        m_list = new QListWidget(m_dock);

        m_list->setFlow(QListView::TopToBottom);
        m_list->setMovement(QListView::Static);
        m_list->setViewMode(QListView::ListMode);
        m_list->setSelectionRectVisible(true);
        m_list->setSelectionBehavior(QAbstractItemView::SelectRows);
        m_list->setSelectionMode(QAbstractItemView::SingleSelection);
        m_dock->setWidget(m_list);

        // Detect item selection changes.
        connect(m_list, &QListWidget::itemSelectionChanged, this, &ActionHistoryPlugin::OnSelectedItemChanged);

        // Register the callback.
        m_callback = new ActionHistoryCallback(m_list);
        EMStudio::GetCommandManager()->RegisterCallback(m_callback);

        // Sync the interface with the actual command history.
        ReInit();
        return true;
    }