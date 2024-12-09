bool ScatterPlotWindow::isXCube(MdiCubeViewport *vp) const {
    return (vp && m_xAxisCube &&
            vp->cube() == m_xAxisCube && vp->grayBand() == m_xAxisCubeBand &&
            vp->isGray());
  }