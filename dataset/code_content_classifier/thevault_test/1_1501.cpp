void ProjectItem::setControlList(ControlList *controlList) {
    setTextColor(Qt::black);
    setText( controlList->name() );
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder.png")
                           .expanded()));
    setData( QVariant::fromValue<ControlList *>(controlList) );
  }