void PlotWindow::showTable() {
    if (plotCurves().size()) {
      if (m_tableWindow == NULL) {
        //m_tableWindow = new TableMainWindow("Plot Table", this);
        m_tableWindow = new TableMainWindow("Plot Table", m_parent);
        m_tableWindow->setTrackListItems(false);
      }

      fillTable();
      m_tableWindow->show();
      m_tableWindow->syncColumns();
    }
  }