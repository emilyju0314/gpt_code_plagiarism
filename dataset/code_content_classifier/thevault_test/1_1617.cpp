void MosaicMainWindow::setupMenus() {
    // Create the file menu
    m_fileMenu = menuBar()->addMenu("&File");

    IString iconDir = FileName("$ISISROOT/appdata/images/icons").expanded();

    QAction *open = new QAction(this);
    open->setText("Open Cube...");
    open->setIcon(QPixmap(QString::fromStdString(iconDir.c_str()) + "/fileopen.png"));
    connect(open, SIGNAL(triggered()), this, SLOT(open()));

    QAction *openList = new QAction(this);
    openList->setText("Open Cube List...");
    openList->setIcon(QPixmap(QString::fromStdString(iconDir.c_str()) + "/mActionHelpContents.png"));
    connect(openList, SIGNAL(triggered()), this, SLOT(openList()));

    QAction *saveProject = new QAction(this);
    saveProject->setText("Save Project");
    saveProject->setShortcut(Qt::CTRL + Qt::Key_S);
    saveProject->setIcon(QPixmap(QString::fromStdString(iconDir.c_str()) + "/mActionFileSave.png"));
    m_actionsRequiringOpen.append(saveProject);
    connect(saveProject, SIGNAL(triggered()), this, SLOT(saveProject()));

    QAction *saveProjectAs = new QAction(this);
    saveProjectAs->setText("Save Project As...");
    saveProjectAs->setIcon(QPixmap(QString::fromStdString(iconDir.c_str()) + "/mActionFileSaveAs.png"));
    m_actionsRequiringOpen.append(saveProjectAs);
    connect(saveProjectAs, SIGNAL(triggered()), this, SLOT(saveProjectAs()));

    QAction *loadProject = new QAction(this);
    loadProject->setText("Load Project...");
    loadProject->setIcon(QPixmap(QString::fromStdString(iconDir.c_str()) + "/mActionExportMapServer.png"));
    connect(loadProject, SIGNAL(triggered()), this, SLOT(loadProject()));

    QAction *closeProject = new QAction(this);
    closeProject->setText("Close Project");
    m_actionsRequiringOpen.append(closeProject);
    connect(closeProject, SIGNAL(triggered()), this, SLOT(closeMosaic()));

    QAction *exit = new QAction(this);
    exit->setText("Exit");
    exit->setIcon(QIcon::fromTheme("window-close"));
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    QAction *actionRequiringOpen = NULL;
    foreach(actionRequiringOpen, m_actionsRequiringOpen) {
      actionRequiringOpen->setEnabled(false);
    }

    QAction *actionRequiringClosed = NULL;
    foreach(actionRequiringClosed, m_actionsRequiringClosed) {
      actionRequiringClosed->setEnabled(true);
    }

    m_fileMenu->addAction(open);
    m_fileMenu->addAction(openList);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(loadProject);
    m_fileMenu->addAction(saveProject);
    m_fileMenu->addAction(saveProjectAs);
    m_fileMenu->addAction(closeProject);
    m_fileMenu->addSeparator();
    m_exportMenu = m_fileMenu->addMenu("&Export");
    m_fileMenu->addAction(exit);

    permanentToolBar()->addAction(loadProject);
    permanentToolBar()->addAction(saveProject);
    permanentToolBar()->addAction(saveProjectAs);
    permanentToolBar()->addSeparator();
    permanentToolBar()->addAction(open);
    permanentToolBar()->addAction(openList);
    permanentToolBar()->addSeparator();

    m_viewMenu = menuBar()->addMenu("&View");
    m_settingsMenu = menuBar()->addMenu("&Settings");
    QMenu *helpMenu = menuBar()->addMenu("&Help");

    QAction *activateWhatsThisAct = new QAction("&What's This", this);
    activateWhatsThisAct->setShortcut(Qt::SHIFT | Qt::Key_F1);
    activateWhatsThisAct->setIcon(
        QPixmap(FileName("$ISISROOT/appdata/images/icons/contexthelp.png").expanded()));
    activateWhatsThisAct->setToolTip("Activate What's This and click on parts "
        "this program to see more information about them");
    connect(activateWhatsThisAct, SIGNAL(triggered()),
            this, SLOT(enterWhatsThisMode()));

    QAction *showHelpAct = new QAction("qmos &Help", this);
    showHelpAct->setIcon(QIcon::fromTheme("help-contents"));
    connect(showHelpAct, SIGNAL(triggered()),
            this, SLOT(showHelp()));

    helpMenu->addAction(activateWhatsThisAct);
    helpMenu->addAction(showHelpAct);

    updateMenuVisibility();
  }