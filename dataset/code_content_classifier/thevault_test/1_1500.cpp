void ProjectItem::setTemplates() {
    setText("Templates");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-red.png")
                           .expanded()));
    setData( QVariant() );

    ProjectItem *mapsItem = new ProjectItem();
    mapsItem->setText("Maps");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-red.png")
                           .expanded()));
    mapsItem->setData( QVariant() );
    appendRow(mapsItem);


    ProjectItem *registrationsItem = new ProjectItem();
    registrationsItem->setText("Registrations");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-red.png")
                           .expanded()));
    registrationsItem->setData( QVariant() );
    appendRow(registrationsItem);
  }