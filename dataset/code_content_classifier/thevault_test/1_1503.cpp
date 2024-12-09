void ProjectItem::setCorrelationMatrix(CorrelationMatrix correlationMatrix) {
    setTextColor(Qt::black);
    setText("Correlation Matrix");
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/network-server-database.png")
                           .expanded()));
    setData( QVariant::fromValue<CorrelationMatrix>(correlationMatrix) );
  }