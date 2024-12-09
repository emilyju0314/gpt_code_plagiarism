void PlotWindow::configurePlotCurves() {
    // make sure that there are CubePlotCurves to configure
    QList<CubePlotCurve *> curves = plotCurves();
    // can't configure 0 curves - menu item is deactivated
    if (curves.size() < 1) {
      return;
    }
    CubePlotCurve *curve = curves.first();
    CubePlotCurveConfigureDialog *configDialog = new CubePlotCurveConfigureDialog(curve, this);
    configDialog->exec();

    emit plotChanged();
  }