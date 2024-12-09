void ProjectItem::setGuiCameraList() {
    setTextColor(Qt::black);
    setText("Sensors");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/camera-photo.png")
                           .expanded()));
    setData( QVariant() );
  }