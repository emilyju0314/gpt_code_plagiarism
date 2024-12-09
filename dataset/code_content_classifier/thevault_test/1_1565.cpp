SensorInfoWidget::SensorInfoWidget(GuiCamera* camera, Directory *directory,
                                     QWidget *parent) : m_ui(new Ui::SensorInfoWidget) {
    m_ui->setupUi(this);

    m_camera = camera;

    // danger here
//    Camera *isisCamera = camera->camera();
    // danger here

    QString displayName = camera->displayProperties()->displayName();

//    CameraDistortionMap *distortionMap = isisCamera->DistortionMap();

    QPixmap image;
    if (displayName.contains("ISSNA")) {
      // TODO Find legal image for this!
      image.load(":cassini-iss-nac");
    }
    else if (displayName.contains("Metric")) {
      image.load(FileName("$ISISROOT/images/icons/nasa_apollo_metric_camera.png")
                          .expanded());
    }
    else if (displayName.contains("HiRISE")) {
      // TODO Find legal image for this!
      image.load(":hirise-camera");
    }

    m_ui->spacecraftlabel->setText(tr("Spacecraft: %1")
                                   .arg(m_camera->spacecraftNameLong()));

    setMinimumWidth(m_ui->tabWidget->minimumWidth()+20);

    m_ui->targetImage->setPixmap(image);

    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setLineWidth(2);

    m_ui->tabWidget->setCurrentIndex(0);

//    m_ui->poleRightAscensionLabel->setText(formatPoleRaString());
//    m_ui->poleDeclinationLabel->setText(formatPoleDecString());
//    m_ui->polePMOffsetLabel->setText(formatPmString());

//    m_ui->aRadiiLabel->setText(tr("%1").arg(m_target->radiusA().kilometers()));
//    m_ui->bRadiiLabel->setText(tr("%1").arg(m_target->radiusB().kilometers()));
//    m_ui->cRadiiLabel->setText(tr("%1").arg(m_target->radiusC().kilometers()));
//    m_ui->meanRadiiLabel->setText(tr("%1").arg(m_target->meanRadius().kilometers()));
  }