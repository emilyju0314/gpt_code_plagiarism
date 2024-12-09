void ProjectItem::setGuiCamera(GuiCameraQsp guiCamera) {
    setTextColor(Qt::black);
    setText( guiCamera->displayProperties()->displayName() );
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/camera-photo.png")
                           .expanded()));
    setData( QVariant::fromValue<GuiCameraQsp>(guiCamera) );
  }