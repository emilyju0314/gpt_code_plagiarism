void RubberBandTool::paintRectangle(QPoint upperLeft, QPoint lowerRight, QPainter *painter) {
    QPoint upperRight = QPoint(lowerRight.x(), upperLeft.y());
    QPoint lowerLeft = QPoint(upperLeft.x(), lowerRight.y());

    paintRectangle(upperLeft, upperRight, lowerLeft, lowerRight, painter);
  }