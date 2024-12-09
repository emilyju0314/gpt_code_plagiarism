void PlotWindow::resetScale() {
    m_zoomer->zoom(0);

    if (m_autoscaleAxes) {
      if (m_xAxisUnits != PlotCurve::Band) {
        m_plot->setAxisAutoScale(QwtPlot::xBottom);
      }
      else {
        QPair<double, double> calculatedXRange = findDataRange(
            QwtPlot::xBottom);
        m_plot->setAxisScale(QwtPlot::xBottom, calculatedXRange.first,
                             calculatedXRange.second);
      }

      if (m_yAxisUnits != PlotCurve::Band) {
        m_plot->setAxisAutoScale(QwtPlot::yLeft);
      }
      else {
        QPair<double, double> calculatedYRange = findDataRange(
            QwtPlot::yLeft);
        m_plot->setAxisScale(QwtPlot::yLeft, calculatedYRange.first,
                             calculatedYRange.second);
      }
    }

    m_zoomer->setZoomBase();
    m_plot->replot();
  }