void ProjectItem::setBundleSolutionInfo(BundleSolutionInfo *bundleSolutionInfo) {
    setTextColor(Qt::black);
    if (bundleSolutionInfo->name() != "") {
      setText( bundleSolutionInfo->name() );
    }
    else {
      setText( bundleSolutionInfo->runTime() );
    }
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/kchart.png")
                           .expanded()));
    setData( QVariant::fromValue<BundleSolutionInfo *>(bundleSolutionInfo) );
  }