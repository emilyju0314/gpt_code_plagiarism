void MotionRetargetingWindow::Init()
    {
        QGridLayout* layout = new QGridLayout();
        setLayout(layout);

        m_motionRetargetingButton = new QCheckBox();
        AzQtComponents::CheckBox::applyToggleSwitchStyle(m_motionRetargetingButton);
        layout->addWidget(new QLabel(tr("Use Motion Retargeting")), 0, 0);
        layout->addWidget(m_motionRetargetingButton, 0, 1);
        connect(m_motionRetargetingButton, &QCheckBox::clicked, this, &MotionRetargetingWindow::UpdateMotions);
    }