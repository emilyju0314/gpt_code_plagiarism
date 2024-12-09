ProjectItem::ProjectItem(QList<BundleSolutionInfo *> results) {
    setTextColor(Qt::black);
    setEditable(false);
    setResults();
    foreach (BundleSolutionInfo *bundleSolutionInfo, results) {
      appendRow( new ProjectItem( bundleSolutionInfo) );
    }
  }