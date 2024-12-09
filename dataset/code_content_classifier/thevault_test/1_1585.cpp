bool PlotWindow::userCanAddCurve(const QMimeData *curve) {
    bool userCanAdd = false;

    if (m_allowUserToAddCurves &&
        curve->hasFormat("application/isis3-plot-curve")) {

      CubePlotCurve * testCurve = new CubePlotCurve(
          curve->data("application/isis3-plot-curve"));

      userCanAdd = canAdd(testCurve);
    }

    return userCanAdd;
  }