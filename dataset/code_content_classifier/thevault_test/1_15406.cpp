std::string CatalogClient::getObjectType(std::string databaseName,
                                         std::string setName,
                                         std::string &errMsg) {

  return simpleRequest<CatSetObjectTypeRequest, CatTypeNameSearchResult, std::string>(
      myLogger, port, address, "", 1024,
      [&](Handle<CatTypeNameSearchResult> result) {
        if (result != nullptr) {
          auto success = result->wasSuccessful();
          if (!success.first) {
            errMsg = "Error getting type name: " + success.second;
            myLogger->error("Error getting type name: " + success.second);
          } else
            return result->getTypeName();
        }
        errMsg = "Error getting type name: got nothing back from catalog";
        return std::string("");
      },
      databaseName, setName);
}