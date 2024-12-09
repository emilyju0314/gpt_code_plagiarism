bool CatalogClient::getSharedLibraryByTypeName(
    int16_t identifier, std::string &typeNameToSearch,
    std::string sharedLibraryFileName, string &sharedLibraryBytes,
    std::string &errMsg) {

  PDB_COUT << "inside CatalogClient getSharedLibraryByTypeName for type=" << typeNameToSearch << " and id=" << identifier << std::endl;

  return simpleRequest<CatSharedLibraryByNameRequest, CatalogUserTypeMetadata,
                       bool>(
      myLogger, port, address, false, 1024 * 1024 * 4,
      [&](Handle<CatalogUserTypeMetadata> result) {

        PDB_COUT << "In CatalogClient- Handling CatSharedLibraryByNameRequest "
                    "received from "
                    "CatalogServer..."
                 << std::endl;
        if (result == nullptr) {
          PDB_COUT << "FATAL ERROR: can't connect to remote server to fetch "
                       "shared library "
                       "for typeId="
                    << identifier << std::endl;
          exit(-1);
        }

        // gets the typeId returned by the Manager Catalog
        auto returnedTypeId = result->typeID;
        PDB_COUT << "Cat Client - Object Id returned " << returnedTypeId
                 << endl;

        if (returnedTypeId == -1) {
          errMsg = "Error getting shared library: type not found in Manager "
                   "Catalog.\n";
          PDB_COUT << "Error getting shared library: type not found in Manager "
                      "Catalog.\n"
                   << endl;
          return false;
        }

        PDB_COUT << "Cat Client - Finally bytes returned " << result->soBytes->size() << endl;

        if (result->soBytes->size() == 0) {
          errMsg = "Error getting shared library, no data returned.\n";
          PDB_COUT << "Error getting shared library, no data returned.\n"
                   << endl;
          return false;
        }

        // gets metadata and bytes of the registered type
        typeNameToSearch = result->typeName.c_str();
        sharedLibraryBytes = string(result->soBytes->c_ptr(), result->soBytes->size());

        PDB_COUT << "   Metadata in Catalog Client " << result->typeID
                 << " | " << result->typeName << " | "
                 << result->typeCategory << endl;

        PDB_COUT << "copying bytes received in CatClient # bytes "
                 << sharedLibraryBytes.size() << endl;

        // just write the shared library to the file
        int filedesc = open(sharedLibraryFileName.c_str(), O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
        PDB_COUT << "Writing file " << sharedLibraryFileName.c_str() << " size is :" << sharedLibraryBytes.size() << "\n";
        write(filedesc, sharedLibraryBytes.c_str(), sharedLibraryBytes.size());
        close(filedesc);

        PDB_COUT << "objectFile is written by CatalogClient" << std::endl;
        return true;
      },
      identifier, typeNameToSearch);
}