void ProjectItem::setTargetBodyList() {
    setTextColor(Qt::black);
    setText("Target Body");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/view-web-browser-dom-tree.png")
                           .expanded()));
    setData( QVariant() );
  }