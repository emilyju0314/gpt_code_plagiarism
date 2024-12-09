bool CatalogClient::createSet(const std::string &typeName, int16_t typeID, const std::string &databaseName,
                              const std::string &setName, std::string &errMsg) {
  PDB_COUT << "CatalogClient: to create set..." << std::endl;
  return simpleRequest<CatCreateSetRequest, SimpleRequestResult, bool>(
      myLogger, port, address, false, 1024,
      [&](Handle<SimpleRequestResult> result) {
        PDB_COUT << "CatalogClient: received response for creating set"
                 << std::endl;
        if (result != nullptr) {
          if (!result->getRes().first) {
            errMsg = "Error creating set: " + result->getRes().second;
            PDB_COUT << "errMsg" << std::endl;
            myLogger->error("Error creating set: " + result->getRes().second);
            return false;
          }
          PDB_COUT << "CatalogClient: created set" << std::endl;
          return true;
        }
        errMsg = "Error getting type name: got nothing back from catalog";
        PDB_COUT << errMsg << std::endl;
        return false;
      },
      databaseName, setName, typeName, typeID);
}