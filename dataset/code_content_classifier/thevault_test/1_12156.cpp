void TrackDataHeaderWidget::DoRecorderContextMenuEvent(QContextMenuEvent* event)
    {
        // create the context menu
        QMenu menu(this);

        //---------------------
        // Timeline actions
        //---------------------
        QAction* action = menu.addAction("Zoom To Fit All");
        connect(action, &QAction::triggered, m_plugin, &TimeViewPlugin::OnZoomAll);

        action = menu.addAction("Reset Timeline");
        connect(action, &QAction::triggered, m_plugin, &TimeViewPlugin::OnResetTimeline);

        // show the menu at the given position
        menu.exec(event->globalPos());
    }