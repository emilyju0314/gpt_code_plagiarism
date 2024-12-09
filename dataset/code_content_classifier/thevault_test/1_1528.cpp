void RubberBandTool::paintVerticesConnected(QPainter *painter) {
    for(int vertex = 1; vertex < p_vertices->size(); vertex++) {
      QPoint start = (*p_vertices)[vertex - 1];
      QPoint end = (*p_vertices)[vertex];

      painter->drawLine(start, end);
    }

    if(p_tracking && (p_vertices->size() > 0)) {
      QPoint start = (*p_vertices)[p_vertices->size() - 1];
      QPoint end = *p_mouseLoc;

      painter->drawLine(start, end);
    }
  }