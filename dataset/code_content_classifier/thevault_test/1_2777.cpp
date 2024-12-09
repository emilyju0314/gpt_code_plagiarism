QStringList LTHEME::currentSettings(){ //returns [theme path, colorspath, iconsname, font, fontsize]
  QStringList out; out << "" << "" << "" << "" << "";
  QStringList settings = LUtils::readFile(QDir::homePath()+"/.lumina/themesettings.cfg");
  for(int i=0; i<settings.length(); i++){
    if(settings[i].startsWith("THEMEFILE=")){ out[0] = settings[i].section("=",1,1).simplified(); }
    else if(settings[i].startsWith("COLORFILE=")){ out[1] = settings[i].section("=",1,1).simplified(); }
    else if(settings[i].startsWith("ICONTHEME=")){ out[2] = settings[i].section("=",1,1).simplified(); }
    else if(settings[i].startsWith("FONTFAMILY=")){ out[3] = settings[i].section("=",1,1).simplified(); }
    else if(settings[i].startsWith("FONTSIZE=")){ out[4] = settings[i].section("=",1,1).simplified(); }
  }
  bool nofile = settings.isEmpty();
  if(out[0].isEmpty() || !QFile::exists(out[0]) ){ out[0] = LOS::LuminaShare()+"themes/Lumina-default.qss.template"; }
  if(out[1].isEmpty() || !QFile::exists(out[1]) ){ out[1] = LOS::LuminaShare()+"colors/Lumina-Glass.qss.colors"; }
  if(out[3].isEmpty()){ out[3] = QFont().defaultFamily(); }
  if(out[4].isEmpty()){ 
    int num = QFont().pointSize(); out[4] = QString::number(num)+"pt"; //Check point size first
    if(num<0){ num = QFont().pixelSize(); out[4] = QString::number(num)+"px";} //Now check pixel size
    if(num<0){ out[4] = "9pt"; } //Now hard-code a fallback (just in case)
  }
  if(nofile){ setCurrentSettings(out[0], out[1], out[2], out[3], out[4]); }
  
  return out;
}