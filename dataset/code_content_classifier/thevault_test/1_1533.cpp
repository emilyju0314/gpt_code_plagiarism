void RubberBandTool::mouseDoubleClick(QPoint p) {
    p_doubleClicking = true;
    *p_mouseLoc = p;

    switch(p_bandingMode) {
      case AngleMode:
      case CircleMode:
      case EllipseMode:
      case LineMode:
      case RectangleMode:
      case RotatedRectangleMode:
        break;

      case SegmentedLineMode:
      case PolygonMode:
        p_tracking = false;
        repaint();
        emit bandingComplete();
        break;
    }
  }