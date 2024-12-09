void RubberBandTool::mouseButtonRelease(QPoint p, Qt::MouseButton s) {
    if ((s & Qt::ControlModifier) == Qt::ControlModifier)
      *p_mouseLoc = snapMouse(p);
    else
      *p_mouseLoc = p;

    p_mouseButton = s;

    if((s & Qt::LeftButton) == Qt::LeftButton || p_allClicks) {
      p_mouseDown = false;
    }
    else {
      return;
    }

    switch(p_bandingMode) {
      case AngleMode: {
          if(p_vertices->size() == 3) {
            reset();
          }

          p_vertices->push_back(*p_mouseLoc);
          p_tracking = true;

          if(p_vertices->size() == 3) {
            p_tracking = false;
            emit bandingComplete();
          }
        }
        break;

      case LineMode:
      case CircleMode:
      case EllipseMode:
      case RectangleMode: {
          *p_vertices = vertices();
          p_tracking = false;
          emit bandingComplete();
        }
        break;

      case RotatedRectangleMode: {
          if(p_vertices->size() == 1) {
            p_vertices->push_back(*p_mouseLoc);
          }
          else if(p_vertices->size() == 2) {
            *p_vertices = vertices();
            p_tracking = false;
            emit bandingComplete();
          }
        }
        break;

      case SegmentedLineMode:
      case PolygonMode:
        break;
    }

    p_doubleClicking = false; // If we were in a double click, it's over now.


    MdiCubeViewport * activeViewport = cubeViewport();
    for (int i = 0; i < (int) cubeViewportList()->size(); i++) {
      MdiCubeViewport * curViewport = cubeViewportList()->at(i);
      if (curViewport == activeViewport ||
          (activeViewport->isLinked() && curViewport->isLinked())) {
        curViewport->viewport()->repaint();
      }
    }
  }