void ScatterPlotWindow::mouseMoveEvent(QMouseEvent *e) {
    if (alarmingViewport()) {
      if (m_alarmViewportUnits == ScreenUnits) {
        m_xCubeDnAlarmRange.first = plot()->invTransform(
            QwtPlot::xBottom, e->pos().x() - m_alarmViewportScreenWidth / 2);
        m_xCubeDnAlarmRange.second = plot()->invTransform(
            QwtPlot::xBottom, e->pos().x() + m_alarmViewportScreenWidth / 2);

        m_yCubeDnAlarmRange.first = plot()->invTransform(
            QwtPlot::yLeft, e->pos().y() + m_alarmViewportScreenHeight / 2);
        m_yCubeDnAlarmRange.second = plot()->invTransform(
            QwtPlot::yLeft, e->pos().y() - m_alarmViewportScreenHeight / 2);

        if (m_xCubeDnAlarmRange.first > m_xCubeDnAlarmRange.second)
          std::swap(m_xCubeDnAlarmRange.first, m_xCubeDnAlarmRange.second);

        if (m_yCubeDnAlarmRange.first > m_yCubeDnAlarmRange.second)
          std::swap(m_yCubeDnAlarmRange.first, m_yCubeDnAlarmRange.second);
      }
      else {
        m_xCubeDnAlarmRange.first = plot()->invTransform(
            QwtPlot::xBottom, e->pos().x()) - m_alarmViewportXDnBoxSize / 2.0;
        m_xCubeDnAlarmRange.second = plot()->invTransform(
            QwtPlot::xBottom, e->pos().x()) + m_alarmViewportXDnBoxSize / 2.0;

        m_yCubeDnAlarmRange.first = plot()->invTransform(
            QwtPlot::yLeft, e->pos().y()) - m_alarmViewportYDnBoxSize / 2.0;
        m_yCubeDnAlarmRange.second = plot()->invTransform(
            QwtPlot::yLeft, e->pos().y()) + m_alarmViewportYDnBoxSize / 2.0;
      }
    }
    else {
      m_xCubeDnAlarmRange.first = Null;
      m_xCubeDnAlarmRange.second = Null;
      m_yCubeDnAlarmRange.first = Null;
      m_yCubeDnAlarmRange.second = Null;
    }

    emit plotChanged();
  }