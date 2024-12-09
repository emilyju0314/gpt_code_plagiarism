QList<QPoint> RubberBandTool::vertices() {
    QList<QPoint> vertices = *p_vertices;

    if(!figureComplete())
      return vertices;

    if(p_tracking) {
      switch(p_bandingMode) {
        case AngleMode:
        case LineMode:
        case SegmentedLineMode:
          vertices.push_back(*p_mouseLoc);
          break;

        case RectangleMode: {
            QPoint corner1 = QPoint(p_mouseLoc->x(), vertices[0].y());
            QPoint corner2 = QPoint(p_mouseLoc->x(), p_mouseLoc->y());
            QPoint corner3 = QPoint(vertices[0].x(), p_mouseLoc->y());
            vertices.push_back(corner1);
            vertices.push_back(corner2);
            vertices.push_back(corner3);
          }
          break;

        case RotatedRectangleMode: {
            QPoint missingVertex;
            calcRectCorners((*p_vertices)[0], (*p_vertices)[1], *p_mouseLoc, missingVertex);
            vertices.push_back(*p_mouseLoc);
            vertices.push_back(missingVertex);
          }
          break;


        case CircleMode: {
            int xradius = abs(p_mouseLoc->x() - vertices[0].x()) / 2;
            int yradius = xradius;

            if(p_mouseLoc->x() - vertices[0].x() < 0) {
              xradius *= -1;
            }

            if(p_mouseLoc->y() - vertices[0].y() < 0) {
              yradius *= -1;
            }

            // Adjust p_vertices[0] from upper left to center
            vertices[0].setX(vertices[0].x() + xradius);
            vertices[0].setY(vertices[0].y() + yradius);

            vertices.push_back(*p_mouseLoc);

            vertices[1].setX(vertices[0].x() + xradius);
            vertices[1].setY(vertices[0].y() + yradius);
          }
          break;

        case EllipseMode: {
            // Adjust p_vertices[0] from upper left to center
            double xradius = (p_mouseLoc->x() - vertices[0].x()) / 2.0;
            double yradius = (p_mouseLoc->y() - vertices[0].y()) / 2.0;
            vertices[0].setX((int)(vertices[0].x() + xradius));
            vertices[0].setY((int)(vertices[0].y() + yradius));

            vertices.push_back(*p_mouseLoc);
          }
          break;

        case PolygonMode:
          break;
      }
    }

    return vertices;
  }