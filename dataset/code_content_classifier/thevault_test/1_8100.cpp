void ConstructMaterials::construct(){

    if (!mu2eStandardDetector_) {
      cout  << "Non standard mu2e configuration, Will NOT construct mu2e materials " << endl;
      // one could move this down to constructMu2eMaterials before using GeomHandle's
      return;
    }

    // Construct the requested materials.
    constructMu2eMaterials();
    constructMu2eMaterials2();

    // Print element table, if requested.
    if (printElements_){
      mf::LogInfo  log("GEOM");
      log << *G4Element::GetElementTable();
    }

    // Print material table, if requested.
    if (printMaterials_){
      mf::LogInfo  log("GEOM");
      log << *G4Material::GetMaterialTable();
    }

  }