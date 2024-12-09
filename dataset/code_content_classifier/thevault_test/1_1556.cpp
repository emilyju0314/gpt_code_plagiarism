void SpectralPlotTool::enableRubberBandTool() {
    if (m_rubberBandCombo) {
      m_rubberBandCombo->reset();
      rubberBandTool()->setDrawActiveViewportOnly(false);

      m_rubberBandCombo->setEnabled(true);
      m_rubberBandCombo->setVisible(true);
    }
  }