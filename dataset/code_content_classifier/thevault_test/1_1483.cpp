ProjectItem::ProjectItem(ImageList *imageList) {
    setTextColor(Qt::black);
    setEditable(true);
    setImageList(imageList);
    foreach (Image *image, *imageList) {
      appendRow( new ProjectItem(image) );
    }
  }