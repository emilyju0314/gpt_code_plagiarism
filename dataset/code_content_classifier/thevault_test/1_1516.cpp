void ScatterPlotWindow::showHideContour() {
    if (m_contour->text() == "Show Contour Lines") {
      m_contour->setText("Hide Contour Lines");
      m_spectrogram->setDisplayMode(QwtPlotSpectrogram::ContourMode, true);
      updateContourPen();
    }
    else {
      m_contour->setText("Show Contour Lines");
      m_spectrogram->setDisplayMode(QwtPlotSpectrogram::ContourMode, false);
    }

    replot();
  }