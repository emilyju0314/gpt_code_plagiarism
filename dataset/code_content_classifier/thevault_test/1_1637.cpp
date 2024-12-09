void MosaicGridTool::drawGrid(bool draw) {
    if (draw) {
      m_autoGridLabel->setEnabled(true);
      m_autoGridCheckBox->setEnabled(true);
      drawGrid();
    }
    else {
      clearGrid();
      m_autoGridLabel->setEnabled(false);
      m_autoGridCheckBox->setEnabled(false);
    }
  }