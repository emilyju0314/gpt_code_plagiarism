bool CatalogClient::shutDownServer(std::string &errMsg) {

  return simpleRequest<ShutDown, SimpleRequestResult, bool>(
      myLogger, port, address, false, 1024,
      [&](Handle<SimpleRequestResult> result) {
        if (result != nullptr) {
          if (!result->getRes().first) {
            errMsg = "Error shutting down server: " + result->getRes().second;
            myLogger->error("Error shutting down server: " +
                            result->getRes().second);
            return false;
          }
          return true;
        }
        errMsg = "Error getting type name: got nothing back from catalog";
        return false;
      });
}