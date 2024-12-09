bool CatalogClient::registerType(std::string fileContainingSharedLib, std::string &errMsg) {

  const LockGuard guard{workingMutex};

  // first, load up the shared library file
  std::ifstream in(fileContainingSharedLib, std::ifstream::ate | std::ifstream::binary);

  // could not open the file
  if (in.fail()) {
    errMsg = "The file " + fileContainingSharedLib + " doesn't exist or cannot be opened.\n";
    return false;
  }

  // grab the file length
  auto fileLen = (size_t) in.tellg();

  // go to the beginning
  in.seekg (0, std::ifstream::beg);

  // load the thing
  auto fileBytes = new char[fileLen];
  in.readsome(fileBytes, fileLen);

  bool res = simpleRequest<CatRegisterType, SimpleRequestResult, bool>(myLogger, port, address, false, 1024 + fileLen,
      [&](Handle<SimpleRequestResult> result) {

        if (result != nullptr) {
          if (!result->getRes().first) {
            errMsg = "Error shutting down server: " + result->getRes().second;
            myLogger->error(errMsg);
            return false;
          }
          return true;
        }

        errMsg = "Error getting type name: got nothing back from catalog";
        return false;

      }, fileBytes, fileLen);

  // free the stuff we loaded
  delete[] fileBytes;

  // return whether we succeeded
  return res;
}