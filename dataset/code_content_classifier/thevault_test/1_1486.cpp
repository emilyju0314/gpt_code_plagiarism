ProjectItem::ProjectItem(QList<ShapeList *> shapes) {
    setTextColor(Qt::black);
    setEditable(false);
    setShapes();
    foreach (ShapeList *shapeList, shapes) {
      appendRow( new ProjectItem(shapeList) );
    }
  }