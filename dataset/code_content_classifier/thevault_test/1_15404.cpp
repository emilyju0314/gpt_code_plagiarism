bool CatalogClient::getSharedLibrary(int16_t identifier,
                                     std::string sharedLibraryFileName) {

  PDB_COUT << "CatalogClient: getSharedLibrary for id=" << identifier << std::endl;
  string sharedLibraryBytes;
  string errMsg;

  // using an empty Name b/c it's being searched by typeId
  string typeNameToSearch;
  bool res = getSharedLibraryByTypeName(identifier, typeNameToSearch, sharedLibraryFileName, sharedLibraryBytes, errMsg);

  PDB_COUT << "CatalogClient: deleted putResultHere " << errMsg << std::endl;
  return res;
}