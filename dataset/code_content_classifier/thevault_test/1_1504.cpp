void ProjectItem::setResults() {
    setTextColor(Qt::black);
    setText("Results");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/kchart.png")
                           .expanded()));
    setData( QVariant() );
  }