ProjectItem::ProjectItem(FileItemQsp filename, QString treeText, QIcon icon) {
    setTextColor(Qt::black);
    setEditable(false);
    setData(QVariant::fromValue<FileItemQsp>(filename));
    setText(treeText);
    setIcon(icon);
  }