void RubberBandTool::mouseButtonPress(QPoint p, Qt::MouseButton s) {
    *p_mouseLoc = p;
    p_mouseButton = s;

    if((s & Qt::LeftButton) != Qt::LeftButton && !p_allClicks) {
      return;
    }

    switch(p_bandingMode) {
      case AngleMode:
        break;

      case CircleMode:
      case EllipseMode:
      case LineMode:
      case RectangleMode:
        reset();
        p_tracking = true;
        p_vertices->push_back(p);
        break;

      case RotatedRectangleMode:
        if(p_vertices->size() == 4) {
          reset();
        }

        if(p_vertices->size() == 0) {
          p_vertices->push_back(p);
          p_tracking = true;
        }
        break;

      case SegmentedLineMode:
      case PolygonMode:
        if(!p_tracking) {
          reset();
          p_tracking = true;
        }

        if(p_vertices->size() == 0 || (*p_vertices)[ p_vertices->size() - 1 ] != p) {
          p_vertices->push_back(p);
        }

        break;
    }

    p_mouseDown = true;
  }