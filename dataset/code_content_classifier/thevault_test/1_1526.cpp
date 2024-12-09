void RubberBandTool::paintViewport(MdiCubeViewport *vp, QPainter *painter) {
    QPen pen(QColor(255, 0, 0));
    QPen greenPen(QColor(0, 255, 0));
    pen.setStyle(Qt::SolidLine);
    greenPen.setStyle(Qt::SolidLine);
    painter->setPen(pen);

    if ( (vp != cubeViewport() && p_drawActiveOnly) ||
        !(vp == cubeViewport() || (cubeViewport()->isLinked() &&
          vp->isLinked()))) {
       return;
     }

    switch(p_bandingMode) {
      case AngleMode:
        paintVerticesConnected(painter);
        break;

      case LineMode:
        // if point needed, draw an X
        if(figureIsPoint() && !p_tracking) {
          painter->drawLine((*p_vertices)[0].x() - 10, (*p_vertices)[0].y() - 10,
                            (*p_vertices)[0].x() + 10, (*p_vertices)[0].y() + 10);
          painter->drawLine((*p_vertices)[0].x() - 10, (*p_vertices)[0].y() + 10,
                            (*p_vertices)[0].x() + 10, (*p_vertices)[0].y() - 10);
        }
        else {
          paintVerticesConnected(painter);
        }

        break;

      case PolygonMode:
        paintVerticesConnected(painter);

        if(!p_tracking && p_vertices->size() > 0) {
          painter->drawLine((*p_vertices)[0], (*p_vertices)[ p_vertices->size() - 1 ]);
        }
        break;

      case CircleMode:
      case EllipseMode: {
          if(p_vertices->size() != 0) {
            QList<QPoint> verticesList = vertices();
            int width = 2 * (verticesList[1].x() - verticesList[0].x());
            int height = 2 * (verticesList[1].y() - verticesList[0].y());

            // upper left x,y,width,height
            painter->drawEllipse(verticesList[0].x() - width / 2, verticesList[0].y() - height / 2,
                                 width,
                                 height
                                );
          }
        }
        break;

      case RectangleMode: {
          if(figureIsPoint() && !p_tracking) {
            painter->drawLine((*p_vertices)[0].x() - 10, (*p_vertices)[0].y() - 10,
                              (*p_vertices)[0].x() + 10, (*p_vertices)[0].y() + 10);
            painter->drawLine((*p_vertices)[0].x() - 10, (*p_vertices)[0].y() + 10,
                              (*p_vertices)[0].x() + 10, (*p_vertices)[0].y() - 10);
          }
          else {
            if(p_tracking && p_vertices->size() > 0) {
              paintRectangle((*p_vertices)[0], *p_mouseLoc, painter);
            }
            else if(p_vertices->size() > 0) {
              paintVerticesConnected(painter);
              painter->drawLine((*p_vertices)[0], (*p_vertices)[ p_vertices->size() - 1 ]);
            }
          }
        }
        break;

      case RotatedRectangleMode: {
          if(p_vertices->size() == 2) {
            QPoint missingVertex;
            calcRectCorners((*p_vertices)[0], (*p_vertices)[1], *p_mouseLoc, missingVertex);
            painter->drawLine(*p_mouseLoc, missingVertex);
            painter->drawLine(missingVertex, (*p_vertices)[0]);
          }
          else if(p_vertices->size() == 4) {
            painter->drawLine((*p_vertices)[0], (*p_vertices)[ 3 ]);
          }

          paintVerticesConnected(painter);

          // Draw indicator on top of original lines if applicable
          if(p_indicatorColors) {
            painter->setPen(greenPen);
            if(p_vertices->size() > 1) {
              painter->drawLine((*p_vertices)[0], (*p_vertices)[1]);
            }
            else if(p_vertices->size() == 1) {
              painter->drawLine((*p_vertices)[0], *p_mouseLoc);
            }

            painter->setPen(pen);
          }
        }
        break;

      case SegmentedLineMode:
        paintVerticesConnected(painter);
        break;
    }
  }