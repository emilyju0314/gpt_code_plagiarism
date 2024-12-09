void ProjectItem::setImageList(ImageList *imageList) {
    setTextColor(Qt::black);
    if (imageList->name() != "") {
      setText( imageList->name() );
    }
    else {
      setText( imageList->path() );
    }
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-image.png")
                           .expanded()));
    setData( QVariant::fromValue<ImageList *>(imageList) );
  }