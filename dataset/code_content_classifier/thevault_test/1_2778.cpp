bool LTHEME::setCurrentSettings(QString themepath, QString colorpath, QString iconname, QString font, QString fontsize){
  QIcon::setThemeName(iconname);
  //Now save the theme settings file	
  QStringList contents;
	contents << "THEMEFILE="+themepath;
	contents << "COLORFILE="+colorpath;
	contents << "ICONTHEME="+iconname;
	contents << "FONTFAMILY="+font;
	contents << "FONTSIZE="+fontsize;
  bool ok = LUtils::writeFile(QDir::homePath()+"/.lumina/themesettings.cfg", contents, true);

  return ok;
}