void PlotWindow::scheduleFillTable() {
    if (!m_scheduledFillTable) {
      m_scheduledFillTable = true;
      emit requestFillTable();
    }
  }