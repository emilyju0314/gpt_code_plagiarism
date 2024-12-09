QStringList DatabaseConnection::getUnappliedMigrations() {
  QDir migrationsDir(":/migrations");

  auto allMigrations = migrationsDir.entryList(QDir::Files, QDir::Name);
  QStringList appliedMigrations;
  QStringList migrationsToApply;

  QSqlQuery dbMigrations("SELECT migration_name FROM migrations");

  if (dbMigrations.exec()) {
    while (dbMigrations.next()) {
      appliedMigrations << dbMigrations.value("migration_name").toString();
    }
  }
  // compare the two list to find gaps
  for (const QString &possibleMigration : allMigrations) {
    if (possibleMigration.right(4) != ".sql") {
      continue;  // assume non-sql files aren't actual migrations.
    }
    auto foundIndex = appliedMigrations.indexOf(possibleMigration);
    if (foundIndex == -1) {
      migrationsToApply << possibleMigration;
    }
    else {
      appliedMigrations.removeAt(foundIndex);
    }
  }
  if (!appliedMigrations.empty()) {
    throw BadDatabaseStateError();
  }
  return migrationsToApply;
}