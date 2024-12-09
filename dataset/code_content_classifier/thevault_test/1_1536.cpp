QPoint RubberBandTool::snapMouse(QPoint p) {
    if (p_vertices->size()) {
      QPoint lastVertex = p_vertices->at(p_vertices->size() - 1);

      int deltaX = abs(p.x() - lastVertex.x());
      int deltaY = abs(p.y() - lastVertex.y());

      if (deltaX > deltaY)
        p.setY(lastVertex.y());
      else
        p.setX(lastVertex.x());
    }

    return p;
  }