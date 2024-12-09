void ScatterPlotWindow::updateContourPen() {
    if (m_colorize->text() == "Gray") {
      m_spectrogram->setDefaultContourPen(QPen(Qt::red));
    }
    else {
      m_spectrogram->setDefaultContourPen(QPen(Qt::white));
    }
  }