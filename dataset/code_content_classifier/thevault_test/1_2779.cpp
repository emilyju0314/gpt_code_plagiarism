QString LTHEME::assembleStyleSheet(QString themepath, QString colorpath, QString font, QString fontsize){
  QString stylesheet = LUtils::readFile(themepath).join("\n");
  QStringList colors = LUtils::readFile(colorpath);
  //qDebug() << "Found Theme:" << themepath << stylesheet;
  //qDebug() << "Found Colors:" << colorpath << colors;
  for(int i=0; i<colors.length(); i++){
    if(colors[i].isEmpty() || colors[i].startsWith("#")){ continue; }
    else if(colors[i].startsWith("PRIMARYCOLOR=")){ stylesheet = stylesheet.replace("%%PRIMARYCOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("SECONDARYCOLOR=")){ stylesheet = stylesheet.replace("%%SECONDARYCOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("HIGHLIGHTCOLOR=")){ stylesheet = stylesheet.replace("%%HIGHLIGHTCOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("ACCENTCOLOR=")){ stylesheet = stylesheet.replace("%%ACCENTCOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("PRIMARYDISABLECOLOR=")){ stylesheet = stylesheet.replace("%%PRIMARYDISABLECOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("SECONDARYDISABLECOLOR=")){ stylesheet = stylesheet.replace("%%SECONDARYDISABLECOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("HIGHLIGHTDISABLECOLOR=")){ stylesheet = stylesheet.replace("%%HIGHLIGHTDISABLECOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("ACCENTDISABLECOLOR=")){ stylesheet = stylesheet.replace("%%ACCENTDISABLECOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("BASECOLOR=")){ stylesheet = stylesheet.replace("%%BASECOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("ALTBASECOLOR=")){ stylesheet = stylesheet.replace("%%ALTBASECOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("TEXTCOLOR=")){ stylesheet = stylesheet.replace("%%TEXTCOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("TEXTDISABLECOLOR=")){ stylesheet = stylesheet.replace("%%TEXTDISABLECOLOR%%", colors[i].section("=",1,1).simplified()); }
    else if(colors[i].startsWith("TEXTHIGHLIGHTCOLOR=")){ stylesheet = stylesheet.replace("%%TEXTHIGHLIGHTCOLOR%%", colors[i].section("=",1,1).simplified()); }
  }
  stylesheet = stylesheet.replace("%%FONT%%", font);
  stylesheet = stylesheet.replace("%%FONTSIZE%%", fontsize);
  //qDebug() << "Assembled Style Sheet:\n" << stylesheet;
  return stylesheet;
}