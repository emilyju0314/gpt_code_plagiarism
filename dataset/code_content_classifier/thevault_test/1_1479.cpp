ProjectItem::ProjectItem(BundleSolutionInfo *bundleSolutionInfo) {
    setTextColor(Qt::black);
    setEditable(false);
    setBundleSolutionInfo(bundleSolutionInfo);

    appendRow( new ProjectItem( bundleSolutionInfo->bundleSettings() ) );
    appendRow( new ProjectItem(bundleSolutionInfo->control()) );
    appendRow( new ProjectItem( bundleSolutionInfo->bundleResults() ) );
    if (!bundleSolutionInfo->adjustedImages().isEmpty()) {
      appendRow( new ProjectItem( bundleSolutionInfo->adjustedImages() ) );
    }
  }