void RubberBandTool::repaint() {
    if(cubeViewport() != NULL) {
      cubeViewport()->viewport()->repaint();
    }
  }