bool CatalogClient::deleteSet(const std::string &databaseName, const std::string &setName, std::string &errMsg) {

  return simpleRequest<CatDeleteSetRequest, SimpleRequestResult, bool>(
      myLogger, port, address, false, 1024,
      [&](Handle<SimpleRequestResult> result) {
        if (result != nullptr) {
          if (!result->getRes().first) {
            errMsg = "Error deleting set: " + result->getRes().second;
            myLogger->error("Error deleting set: " + result->getRes().second);
            return false;
          }
          return true;
        }
        errMsg = "Error getting type name: got nothing back from catalog";
        return false;
      },
      databaseName, setName);
}