DatabaseConnection::DatabaseConnection() {
  QString dbPath = Constants::dbLocation();
  const QString DRIVER("QSQLITE");
  if (QSqlDatabase::isDriverAvailable(DRIVER)) {
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(dbPath);
    auto dbFileRoot = dbPath.left(dbPath.lastIndexOf("/"));
    QDir().mkpath(dbFileRoot);
  }
  else {
    throw DBDriverUnavailableError("SQLite");
  }
}