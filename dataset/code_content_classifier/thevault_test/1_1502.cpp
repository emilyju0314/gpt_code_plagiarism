void ProjectItem::setControls() {
    setTextColor(Qt::black);
    setText("Control Networks");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-remote.png")
                           .expanded()));
    setData( QVariant() );
  }