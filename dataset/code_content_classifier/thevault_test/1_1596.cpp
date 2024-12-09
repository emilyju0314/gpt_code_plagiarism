void PlotWindow::paint(MdiCubeViewport *vp, QPainter *painter) {
    foreach (CubePlotCurve *curve, plotCurves()) {
      curve->paint(vp, painter);
    }
  }