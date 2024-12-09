bool ScatterPlotWindow::isYCube(MdiCubeViewport *vp) const {
    return (vp && m_yAxisCube &&
            vp->cube() == m_yAxisCube && vp->grayBand() == m_yAxisCubeBand &&
            vp->isGray());
  }