void ProjectItem::setBundleSettings(BundleSettingsQsp bundleSettings) {
    setTextColor(Qt::black);
    setText("Settings");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/applications-system.png")
                           .expanded()));
    setData( QVariant::fromValue<BundleSettingsQsp>(bundleSettings) );
  }