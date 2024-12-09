void PlotWindow::setLabels() {
    m_plot->setTitle(m_plotTitleText->text());
    m_plot->setAxisTitle(QwtPlot::xBottom, m_xAxisText->text());
    m_plot->setAxisTitle(QwtPlot::yLeft, m_yAxisText->text());
    /*Replot with new labels.*/
    m_plot->replot();
  }