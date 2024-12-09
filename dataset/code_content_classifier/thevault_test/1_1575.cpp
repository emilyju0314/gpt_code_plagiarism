void PlotWindow::trackerEnabled() {
    if (m_zoomer->trackerMode() == QwtPicker::ActiveOnly) {
      m_zoomer->setTrackerMode(QwtPicker::AlwaysOn);
    }
    else {
      m_zoomer->setTrackerMode(QwtPicker::ActiveOnly);
    }
  }