void PlotWindow::clearPlot() {
    clearPlotCurves();

    /*Table Stuff if table is open*/
    if (m_tableWindow != NULL && m_tableWindow->isVisible()) {
      m_tableWindow->table()->setColumnCount(1);
      m_tableWindow->table()->setRowCount(0);
//       deleteFromTable();
    }
  }