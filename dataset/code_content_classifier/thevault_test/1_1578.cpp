void PlotWindow::switchBackground() {
    QPen *pen = new QPen(Qt::white);

    if (m_plot->canvasBackground() == Qt::white) {
      m_plot->setCanvasBackground(Qt::black);
      m_grid->setMajorPen(QPen(Qt::white, 1, Qt::DotLine));
    }
    else {
      m_plot->setCanvasBackground(Qt::white);
      pen->setColor(Qt::black);
      m_grid->setMajorPen(QPen(Qt::black, 1, Qt::DotLine));
    }

    m_zoomer->setRubberBandPen(*pen);
    m_zoomer->setTrackerPen(*pen);
    pen->setWidth(2);
    /*Replot with the new background and pen colors*/
    m_plot->replot();
  }