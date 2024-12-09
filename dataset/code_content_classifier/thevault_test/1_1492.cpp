void ProjectItem::setBundleResults(BundleResults bundleResults) {
    setTextColor(Qt::black);
    setText("Statistics");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/kchart.png")
                           .expanded()));
    setData( QVariant::fromValue<BundleResults>(bundleResults) );
  }