bool CatalogClient::registerNodeMetadata(pdb::Handle<pdb::CatSyncRequest> nodeData, std::string &errMsg) {

  PDB_COUT << "registerNodeMetadata for item: " << (*nodeData) << endl;

  return simpleRequest<CatSyncRequest, SimpleRequestResult, bool>(
      myLogger, port, address, false, 1024,
      [&](Handle<SimpleRequestResult> result) {
        if (result != nullptr) {
          if (!result->getRes().first) {
            errMsg =
                "Error registering node metadata: " + result->getRes().second;
            myLogger->error("Error registering node metadata: " +
                            result->getRes().second);
            return false;
          }
          return true;
        }
        errMsg = "Error registering node metadata in the catalog";
        return false;
      },
      nodeData);
}