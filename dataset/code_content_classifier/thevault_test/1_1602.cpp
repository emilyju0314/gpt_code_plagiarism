WarningWidget::WarningWidget(QStatusBar *pParent): QObject(pParent) {
    mSBar = pParent;

    QString sToolIconDir = FileName("$ISISROOT/appdata/images/icons").expanded();
    QString qsIconFile(sToolIconDir);

    // default Action - No warning
    mNoWarning = new QPushButton(mSBar);
    mNoWarning->setFixedSize(22, 22) ;
    mNoWarning->setFlat(true);
    mNoWarning->setIconSize(QSize(15, 15));
    mNoWarning->setIcon(QPixmap(qsIconFile + "/qview_NoWarning.png"));
    mNoWarning->setToolTip("No Warning");
    mNoWarning->setVisible(true);
    // Add Nowarning object to the layout of the active tool bar of the Tool
    mSBar->insertPermanentWidget(0, mNoWarning);

    mSBar->showMessage("Ready");
    mMsgStr = QString("Ready");

    // Warning is not set
    mbWarningFlag = false;

    // Dialog box displayed when the Warning Icon is clicked
    mDialog = new QDialog(mSBar);
    mDialog->setWindowTitle("Warning");
    mDialog->setSizeGripEnabled(true);
    mWindow = new QWidget(mDialog);
    mWindow->installEventFilter(this);//receive events directed to this object

    mTextEdit = new QTextEdit(mDialog);
    mTextEdit->setReadOnly(true);
    QFont font("Helvetica", 11);
    mTextEdit->setFont(font);

    // OK button for the dialog window
    QPushButton *okButton = new QPushButton("Ok", mDialog);
    okButton->setShortcut(Qt::Key_Enter);
    connect(okButton, SIGNAL(clicked()),  this, SLOT(resetWarning()));  //when clicked close dialog and display Nowarning icon

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(mTextEdit, 0, 0, 1, 3);
    layout->addWidget(okButton, 1, 1, 1, 1);
    mDialog->setLayout(layout);

    // Warning object
    mWarning = new QPushButton(mSBar);
    mWarning->setFixedSize(22, 22) ;
    mWarning->setFlat(false);
    mWarning->setIconSize(QSize(15, 15));
    mWarning->setIcon(QPixmap(qsIconFile + "/qview_Warning.png"));
    mWarning->setToolTip("Warning");
    mWarning->setVisible(false);
    mSBar->insertPermanentWidget(0, mWarning);

    connect(mWarning, SIGNAL(clicked()), mDialog, SLOT(show())); // display the dialog window when this button is clicked
    mDialog->resize(800, 250);
    mTextEdit->setBaseSize(750, 200) ;
  }