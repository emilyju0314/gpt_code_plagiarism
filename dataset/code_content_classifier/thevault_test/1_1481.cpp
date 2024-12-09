ProjectItem::ProjectItem(QList<ControlList *> controls) {
    setTextColor(Qt::black);
    setEditable(false);
    setControls();
    foreach (ControlList *controlList, controls) {
      appendRow( new ProjectItem(controlList) );
    }
  }