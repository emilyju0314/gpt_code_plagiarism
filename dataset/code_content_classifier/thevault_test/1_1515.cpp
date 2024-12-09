void ScatterPlotWindow::colorPlot() {
    if (m_colorize->text().compare("Colorize") == 0) {
      m_colorize->setIcon(QPixmap(FileName("$ISISROOT/appdata/images/icons/gray.png").expanded()));
      m_colorize->setText("Gray");
      QwtLinearColorMap *colorMap = new QwtLinearColorMap(Qt::darkCyan, Qt::red);
      colorMap->addColorStop(DBL_EPSILON, Qt::cyan);
      colorMap->addColorStop(0.3, Qt::green);
      colorMap->addColorStop(0.50, Qt::yellow);
      m_spectrogram->setColorMap(colorMap);
      plot()->setCanvasBackground(Qt::darkCyan);
    }
    else {
      m_colorize->setIcon(QPixmap(FileName("$ISISROOT/appdata/images/icons/rgb.png").expanded()));
      m_colorize->setText("Colorize");
      QwtLinearColorMap *colorMap = new QwtLinearColorMap(Qt::black, Qt::white);
      colorMap->addColorStop(DBL_EPSILON, Qt::darkGray);
      m_spectrogram->setColorMap(colorMap);
      plot()->setCanvasBackground(Qt::black);
    }

//    plot()->axisWidget(QwtPlot::yRight)->setColorMap(
//        m_spectrogram->interval(Qt::ZAxis),
//        m_spectrogram->colorMap());
    updateContourPen();

    replot();
  }