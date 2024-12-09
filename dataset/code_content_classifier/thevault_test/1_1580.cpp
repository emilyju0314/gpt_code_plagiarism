void PlotWindow::setUserValues() {
    if (m_xLogCheckBox->isChecked()) {
      m_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
      m_plotXLogScale = true;
    }
    else {
      m_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLinearScaleEngine);
      m_plotXLogScale = false;
    }

    if (m_yLogCheckBox->isChecked()) {
      m_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine);
      m_plotYLogScale = true;
    }
    else {
      m_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine);
      m_plotYLogScale = false;
    }

    m_autoscaleAxes = m_autoScaleCheckBox->isChecked();

    if (!m_autoscaleAxes) {
      double xMin = m_xMinEdit->text().toDouble();
      double xMax = m_xMaxEdit->text().toDouble();
  //  QwtScaleDiv xAxisScale =
  //      m_plot->axisScaleEngine(QwtPlot::xBottom)->divideScale(xMin, xMax,
  //                                                             25, 100);
  //  m_plot->setAxisScaleDiv(QwtPlot::xBottom, xAxisScale);
      m_plot->setAxisScale(QwtPlot::xBottom, xMin, xMax);

      double yMin = m_yMinEdit->text().toDouble();
      double yMax = m_yMaxEdit->text().toDouble();
  //  QwtScaleDiv yAxisScale =
  //      m_plot->axisScaleEngine(QwtPlot::yLeft)->divideScale(yMin, yMax,
  //                                                             25, 100);
  //  m_plot->setAxisScaleDiv(QwtPlot::yLeft, yAxisScale);
      m_plot->setAxisScale(QwtPlot::yLeft, yMin, yMax);

      m_zoomer->setZoomBase();
    }

    replot();
  }