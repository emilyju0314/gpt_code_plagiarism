void MosaicGridTool::onCubesChanged() {
    if (m_previousBoundingRect != getWidget()->cubesBoundingRect()) {
      emit boundingRectChanged();
      autoGrid(m_autoGridCheckBox->isChecked());

      //Make sure that the grid is updated the first time new cubes are opened.
      getWidget()->getView()->update();
      QApplication::processEvents();
    }
  }