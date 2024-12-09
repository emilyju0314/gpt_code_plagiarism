ProjectItem::ProjectItem(ShapeList *shapeList) {
    setTextColor(Qt::black);
    setEditable(false);
    setShapeList(shapeList);
    foreach (Shape *shape, *shapeList) {
      appendRow(new ProjectItem(shape));
    }
  }