void PlotWindow::showHideGrid() {
    m_grid->setVisible(!m_grid->isVisible());

    if (m_grid->isVisible()) {
      m_showHideGrid->setText("Hide Grid");
    }
    else {
      m_showHideGrid->setText("Show Grid");
    }
    m_plot->replot();
  }