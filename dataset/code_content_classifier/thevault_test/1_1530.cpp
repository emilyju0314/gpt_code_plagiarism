void RubberBandTool::paintRectangle(QPoint upperLeft, QPoint upperRight,
                                      QPoint lowerLeft, QPoint lowerRight, QPainter *painter) {
    painter->drawLine(upperLeft, upperRight);
    painter->drawLine(upperRight, lowerRight);
    painter->drawLine(lowerRight, lowerLeft);
    painter->drawLine(lowerLeft, upperLeft);
  }