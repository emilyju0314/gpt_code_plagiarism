void ProjectItem::setShapeList(ShapeList *shapeList) {
    setTextColor(Qt::black);
    if (shapeList->name() != "") {
      setText( shapeList->name() );
    }
    else {
      setText( shapeList->path() );
    }
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-orange.png")
                           .expanded()));
    setData( QVariant::fromValue<ShapeList *>(shapeList) );
  }