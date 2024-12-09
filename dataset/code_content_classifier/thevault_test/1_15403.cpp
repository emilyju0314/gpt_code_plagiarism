PDBCatalogTypePtr CatalogClient::getType(const std::string &typeName, std::string &error) {

  PDB_COUT << "Searching for type with the name : " << typeName << "\n";
  return simpleRequest<CatGetType, CatGetTypeResult, PDBCatalogTypePtr>(
      myLogger, port, address, nullptr, 1024 * 1024,
      [&](Handle<CatGetTypeResult> result) {
        if (result != nullptr) {
          PDB_COUT << "Got a type with the type id :" << result->typeID << "\n";
          return std::make_shared<PDBCatalogType>(result->typeID, (std::string) result->typeCategory, result->typeName, std::vector<char>());
        } else {
          PDB_COUT << "searchForObjectTypeName: error in getting typeId\n";
          return (PDBCatalogTypePtr) nullptr;
        }
      },
      typeName);
}