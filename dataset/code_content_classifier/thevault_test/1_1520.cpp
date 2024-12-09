void ScatterPlotWindow::mouseLeaveEvent(QMouseEvent *e) {
    m_xCubeDnAlarmRange.first = Null;
    m_xCubeDnAlarmRange.second = Null;
    m_yCubeDnAlarmRange.first = Null;
    m_yCubeDnAlarmRange.second = Null;

    emit plotChanged();
  }