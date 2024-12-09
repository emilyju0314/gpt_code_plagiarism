void Tool::removeViewportConnections() {
    if(m_cvp == NULL)
      return;

    disconnect(m_cvp, SIGNAL(scaleChanged()),
               this, SLOT(scaleChanged()));

    if (rubberBandTool()) {
      disconnect(rubberBandTool(), SIGNAL(measureChange()),
                 this, SLOT(updateMeasure()));

      disconnect(rubberBandTool(), SIGNAL(bandingComplete()),
                 this, SLOT(rubberBandComplete()));
    }

    disconnect(m_cvp, SIGNAL(mouseEnter()),
               this, SLOT(mouseEnter()));

    disconnect(m_cvp, SIGNAL(screenPixelsChanged()),
               this, SLOT(screenPixelsChanged()));

    disconnect(m_cvp, SIGNAL(mouseMove(QPoint)),
               this, SLOT(mouseMove(QPoint)));

    disconnect(m_cvp, SIGNAL(mouseMove(QPoint, Qt::MouseButton)),
               this, SLOT(mouseMove(QPoint, Qt::MouseButton)));

    disconnect(m_cvp, SIGNAL(mouseLeave()),
               this, SLOT(mouseLeave()));

    disconnect(m_cvp, SIGNAL(mouseDoubleClick(QPoint)),
               this, SLOT(mouseDoubleClick(QPoint)));

    disconnect(m_cvp, SIGNAL(mouseButtonPress(QPoint, Qt::MouseButton)),
               this, SLOT(mouseButtonPress(QPoint, Qt::MouseButton)));

    disconnect(m_cvp, SIGNAL(mouseButtonRelease(QPoint, Qt::MouseButton)),
               this, SLOT(mouseButtonRelease(QPoint, Qt::MouseButton)));

    removeConnections(m_cvp);
  }