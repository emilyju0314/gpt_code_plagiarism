bool CatalogClient::deleteDatabase(const std::string &databaseName, std::string &errMsg) {

  return simpleRequest<CatDeleteDatabaseRequest, SimpleRequestResult, bool>(
      myLogger, port, address, false, 1024,
      [&](Handle<SimpleRequestResult> result) {
        if (result != nullptr) {
          if (!result->getRes().first) {
            errMsg = "Error deleting database: " + result->getRes().second;
            myLogger->error("Error deleting database: " +
                            result->getRes().second);
            return false;
          }
          return true;
        }
        errMsg = "Error getting type name: got nothing back from catalog";
        return false;
      },
      databaseName);
}