bool LTHEME::saveLocalTheme(QString name, QStringList contents){
  QString localdir = QDir::homePath()+"/.lumina/themes/";
  if(!QFile::exists(localdir)){  QDir dir; dir.mkpath(localdir); }
  return LUtils::writeFile(localdir+name+".qss.template", contents, true);
}