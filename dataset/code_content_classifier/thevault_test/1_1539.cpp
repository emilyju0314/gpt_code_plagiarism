QRect RubberBandTool::rectangle() {
    QRect rect;

    if(currentMode() == RectangleMode && figureValid()) {
      QList<QPoint> verticesList = vertices();

      //Check the corners for upper left and lower right.
      int x1, x2, y1, y2;
      //Point 1 is in the left, make point1.x upperleft.x
      if(verticesList[0].x() < verticesList[2].x()) {
        x1 = verticesList[0].x();
        x2 = verticesList[2].x();
      }
      //Otherwise Point1 is in the right, make point1.x lowerright.x
      else {
        x1 = verticesList[2].x();
        x2 = verticesList[0].x();
      }

      //Point 1 is in the top, make point1.y upperleft.y
      if(verticesList[0].y() < verticesList[2].y()) {
        y1 = verticesList[0].y();
        y2 = verticesList[2].y();
      }
      //Otherwise Point1 is in the bottom, make point1.y lowerright.y
      else {
        y1 = verticesList[2].y();
        y2 = verticesList[0].y();
      }

      rect = QRect(x1, y1, x2 - x1, y2 - y1);
    }
    //RectangleMode is not valid, or RubberBandTool is in the wrong mode, return error
    else {
      QMessageBox::information((QWidget *)parent(),
                               "Error", "**PROGRAMMER ERROR** Invalid RectangleMode");
    }

    return rect;
  }