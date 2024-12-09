string CatalogClient::printCatalogMetadata(std::string &categoryToPrint, std::string &errMsg) {

  pdb::Handle<pdb::CatPrintCatalogRequest> itemToPrint = pdb::makeObject<CatPrintCatalogRequest>("", categoryToPrint);

  return simpleRequest<pdb::CatPrintCatalogRequest, CatPrintCatalogResult, string>(myLogger, port, address, "", 1024,
      [&](Handle<CatPrintCatalogResult> result) {
        if (result != nullptr) {
          string resultToPrint = result->output;
          return resultToPrint;
        }
        errMsg = "Error printing catalog metadata.";
        return errMsg;
      },
      itemToPrint);
}