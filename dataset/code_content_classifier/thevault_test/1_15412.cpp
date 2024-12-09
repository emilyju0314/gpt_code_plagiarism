string CatalogClient::printCatalogMetadata(pdb::Handle<pdb::CatPrintCatalogRequest> itemToSearch,
                                           std::string &errMsg) {

  PDB_COUT << "Category to print" << itemToSearch->category.c_str() << "\n";

  return simpleRequest<pdb::CatPrintCatalogRequest, CatPrintCatalogResult, string>(
      myLogger, port, address, "", 1024,
      [&](Handle<CatPrintCatalogResult> result) {
        if (result != nullptr) {
          string res = result->output;
          return res;
        }
        errMsg = "Error printing catalog metadata.";
        return errMsg;
      },
      itemToSearch);
}