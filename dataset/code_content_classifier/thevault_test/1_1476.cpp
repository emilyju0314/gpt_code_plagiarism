ProjectItem::ProjectItem(FileItemQsp filename, QString treeText, QString toolTipText,
                           QIcon icon) {
    setTextColor(Qt::black);
    setEditable(false);
    setData(QVariant::fromValue<FileItemQsp>(filename));
    setText(treeText);
    setToolTip(toolTipText);
    setIcon(icon);
  }