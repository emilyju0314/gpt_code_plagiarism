ProjectItem::ProjectItem(ProjectItem *item) {
    setTextColor(Qt::black);
    item->setEditable(false);
    setProjectItem(item);
    for (int i=0; i < item->rowCount(); i++) {
      appendRow(new ProjectItem( item->child(i) ) );
    }
  }