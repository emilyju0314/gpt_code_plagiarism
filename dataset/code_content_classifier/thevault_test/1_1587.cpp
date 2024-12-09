void PlotWindow::setMenus(QList<QMenu *> menu, QList<QAction *> actions) {
    if (m_toolBar == NULL) {
      m_toolBar = new QToolBar(this);
      m_toolBar->setObjectName("PlotWindow");
      m_toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea | Qt::TopToolBarArea);
      addToolBar(Qt::TopToolBarArea, m_toolBar);
    }
    else {
      m_toolBar->clear();
    }

    m_menubar = menuBar();
    m_menubar->clear();

    for (int i = 0; i < menu.size(); i++) {
      m_menubar->addMenu(menu[i]);
    }

    for (int i = 0; i < actions.size(); i++) {
      m_toolBar->addAction(actions[i]);
    }

  }