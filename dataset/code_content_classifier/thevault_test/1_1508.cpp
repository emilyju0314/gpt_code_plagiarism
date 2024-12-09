void ProjectItem::setTargetBody(TargetBodyQsp targetBody) {
    setTextColor(Qt::black);
    setText( targetBody->displayProperties()->displayName() );
    if (targetBody->displayProperties()->displayName() == "MOON")
      setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/weather-clear-night.png")
                             .expanded()));
    else if (targetBody->displayProperties()->displayName() == "Enceladus")
      setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/nasa_enceladus.png")
                             .expanded()));
    else if (targetBody->displayProperties()->displayName() == "Mars")
      setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/nasa_mars.png")
                             .expanded()));
    else if (targetBody->displayProperties()->displayName() == "Titan")
      setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/nasa_titan.png")
                             .expanded()));
    else
      setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/view-web-browser-dom-tree.png")
                             .expanded()));

    setData( QVariant::fromValue<TargetBodyQsp>(targetBody) );
  }