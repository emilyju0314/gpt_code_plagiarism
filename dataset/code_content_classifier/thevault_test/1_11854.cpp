void DockTabBar::contextMenuEvent(QContextMenuEvent* event)
    {
        // Figure out the index of the tab the event was triggered on, or use
        // the currently active tab if the event was triggered in the header
        // dead zone
        int index = tabAt(event->pos());
        if (index == -1 && !m_isShowingWindowControls)
        {
            index = currentIndex();
        }
        m_menuActionTabIndex = index;

        // Need to create our context menu/actions if this is the first time
        // it has been invoked
        if (!m_contextMenu)
        {
            m_contextMenu = new QMenu(this);

            // Action to close the specified tab, and leave the text blank since
            // it will be dynamically set using the title of the specified tab
            m_closeTabMenuAction = m_contextMenu->addAction(QString());
            QObject::connect(m_closeTabMenuAction, &QAction::triggered, this, [this]() { emit closeTab(m_menuActionTabIndex); });

            // Action to close all of the tabs in our tab widget
            m_closeTabGroupMenuAction = m_contextMenu->addAction(tr("Close Tab Group"));
            QObject::connect(m_closeTabGroupMenuAction, &QAction::triggered, this, &DockTabBar::closeTabGroup);

            // Separate the close actions from the undock actions
            m_contextMenu->addSeparator();

            // Action to undock the specified tab, and leave the text blank since
            // it will be dynamically set using the title of the specified tab
            m_undockTabMenuAction = m_contextMenu->addAction(QString());
            QObject::connect(m_undockTabMenuAction, &QAction::triggered, this, [this]() { emit undockTab(m_menuActionTabIndex); });

            // Action to undock the entire tab widget
            m_undockTabGroupMenuAction = m_contextMenu->addAction(tr("Undock Tab Group"));
            QObject::connect(m_undockTabGroupMenuAction, &QAction::triggered, this ,[this]() { emit undockTab(-1); });
        }

        if (index >= 0)
        {
            // Update the menu labels for the close/undock individual tab actions
            QString tabName = tabText(index);
            m_closeTabMenuAction->setText(tr("Close %1").arg(tabName));
            m_undockTabMenuAction->setText(tr("Undock %1").arg(tabName));

            // Only enable the close/undock group actions if we have more than one
            // tab in our tab widget
            bool enableGroupActions = (count() > 1);
            m_closeTabGroupMenuAction->setEnabled(enableGroupActions);

            // Don't enable the undock action if this dock widget is the only pane
            // in a floating window or if it isn't docked in one of our dock main windows
            QWidget* tabWidget = parentWidget();
            bool enableUndock = true;
            if (tabWidget)
            {
                // The main case is when we have a tab bar for a tab widget
                QWidget* tabWidgetParent = tabWidget->parentWidget();
                StyledDockWidget* dockWidgetContainer = qobject_cast<StyledDockWidget*>(tabWidgetParent);
                if (!dockWidgetContainer)
                {
                    // The other case is when this tab bar is being used for a solo dock widget by the TitleBar
                    // so that it looks like a tab, so we need to look one level up
                    dockWidgetContainer = qobject_cast<StyledDockWidget*>(tabWidgetParent->parentWidget());
                }

                if (dockWidgetContainer)
                {
                    DockMainWindow* dockMainWindow = qobject_cast<DockMainWindow*>(dockWidgetContainer->parentWidget());

                    enableUndock = dockMainWindow && !dockWidgetContainer->isSingleFloatingChild();
                }
            }
            m_undockTabGroupMenuAction->setEnabled(enableGroupActions && enableUndock);

            // Enable the undock action if there are multiple tabs or if this isn't
            // a single tab in a floating window
            m_undockTabMenuAction->setEnabled(enableGroupActions || enableUndock);

            // Show the context menu
            m_contextMenu->exec(event->globalPos());
        }
        else
        {
            // Show Window context menu

            // The Floating Window structure is fixed, so we should always get the parent. If we don't, bail out.
            if (!parent() || !parent()->parent() || !parent()->parent()->parent())
            {
                AZ_Warning("DockTabBar", false,
                    "Could not access the parent floating window to trigger its context menu - invalid floating window structure?");
                return;
            }

            auto parentFloatingWindow = qobject_cast<StyledDockWidget*>(parent()->parent()->parent()->parent());
            if (parentFloatingWindow)
            {
                auto parentFloatingWindowTitleBar = qobject_cast<AzQtComponents::TitleBar*>(parentFloatingWindow->customTitleBar());
                if (parentFloatingWindowTitleBar)
                {
                    QContextMenuEvent contextMenuEvent(QContextMenuEvent::Reason::Mouse, event->pos(), event->globalPos());
                    QApplication::sendEvent(parentFloatingWindowTitleBar, &contextMenuEvent);
                }
            }
        }
    }