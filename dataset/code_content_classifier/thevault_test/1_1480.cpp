ProjectItem::ProjectItem(ControlList *controlList) {
    setTextColor(Qt::black);
    setEditable(false);
    setControlList(controlList);
    foreach (Control *control, *controlList) {
      appendRow( new ProjectItem(control) );
    }
  }