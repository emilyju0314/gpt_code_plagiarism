QStringList SpiceDbGen::GetFiles(FileName location, QString filter) {
  filter.remove("\\");
  QDir dir(location.expanded(), filter,
           QDir::Name, QDir::Files);
  return dir.entryList();
}