ProjectItem::ProjectItem(QList<ImageList *> images) {
    setTextColor(Qt::black);
    setEditable(false);
    setImages();
    foreach (ImageList *imageList, images) {
      appendRow( new ProjectItem(imageList) );
    }
  }