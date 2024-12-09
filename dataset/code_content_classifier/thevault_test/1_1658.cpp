void Tool::addViewportConnections() {
    if(m_cvp == NULL)
      return;

    connect(m_cvp, SIGNAL(scaleChanged()),
            this, SLOT(scaleChanged()));

    if (rubberBandTool()) {
      connect(rubberBandTool(), SIGNAL(measureChange()),
              this, SLOT(updateMeasure()));

      connect(rubberBandTool(), SIGNAL(bandingComplete()),
              this, SLOT(rubberBandComplete()));
    }

    connect(m_cvp, SIGNAL(mouseEnter()),
            this, SLOT(mouseEnter()));

    connect(m_cvp, SIGNAL(screenPixelsChanged()),
            this, SLOT(screenPixelsChanged()));

    connect(m_cvp, SIGNAL(mouseMove(QPoint)),
            this, SLOT(mouseMove(QPoint)), Qt::DirectConnection);

    connect(m_cvp, SIGNAL(mouseMove(QPoint, Qt::MouseButton)),
            this, SLOT(mouseMove(QPoint, Qt::MouseButton)), Qt::DirectConnection);

    connect(m_cvp, SIGNAL(mouseLeave()),
            this, SLOT(mouseLeave()));

    connect(m_cvp, SIGNAL(mouseDoubleClick(QPoint)),
            this, SLOT(mouseDoubleClick(QPoint)));

    connect(m_cvp, SIGNAL(mouseButtonPress(QPoint, Qt::MouseButton)),
            this, SLOT(mouseButtonPress(QPoint, Qt::MouseButton)));

    connect(m_cvp, SIGNAL(mouseButtonRelease(QPoint, Qt::MouseButton)),
            this, SLOT(mouseButtonRelease(QPoint, Qt::MouseButton)));

    addConnections(m_cvp);

    if(m_toolPadAction != NULL) {
      enableRubberBandTool();
    }
  }