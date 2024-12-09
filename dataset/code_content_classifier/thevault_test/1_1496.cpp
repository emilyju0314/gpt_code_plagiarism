void ProjectItem::setImages() {
    setTextColor(Qt::black);
    setText("Images");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-image.png")
                           .expanded()));
    setData( QVariant() );
  }