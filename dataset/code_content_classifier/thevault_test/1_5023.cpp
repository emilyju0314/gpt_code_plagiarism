QSqlQuery DatabaseConnection::executeQuery(QSqlDatabase *db, const QString &stmt,
                                           const std::vector<QVariant> &args) {
  QSqlQuery query(*db);

  if (!query.prepare(stmt)) {
    throw query.lastError();
  }

  for (const auto &arg : args) {
    query.addBindValue(arg);
  }

  if (!query.exec()) {
    throw query.lastError();
  }
  return query;
}