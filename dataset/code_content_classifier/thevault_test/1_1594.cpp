void PlotWindow::pasteCurve() {
    if (m_allowUserToAddCurves) {
      QClipboard *globalClipboard = QApplication::clipboard();
      const QMimeData *globalData = globalClipboard->mimeData();

      if (globalData->hasFormat("application/isis3-plot-curve")) {
        CubePlotCurve * newCurve = new CubePlotCurve(
                globalData->data("application/isis3-plot-curve"));
        // add curve to plot
        add(newCurve);
        emit plotChanged();
      }
    }
  }