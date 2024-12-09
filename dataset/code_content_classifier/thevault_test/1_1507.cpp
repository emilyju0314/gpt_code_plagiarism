void ProjectItem::setSpacecraft() {
    setTextColor(Qt::black);
    setText("Spacecraft");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/preferences-desktop-launch-feedback.png")
                           .expanded()));
    setData( QVariant() );
  }