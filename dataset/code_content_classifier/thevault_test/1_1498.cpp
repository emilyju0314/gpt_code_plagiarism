void ProjectItem::setShapes() {
    setTextColor(Qt::black);
    setText("Shapes");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-red.png")
                           .expanded()));
    setData( QVariant() );
  }