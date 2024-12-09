void cnetstats(ControlNet &innet, QString &serialNumFile, UserInterface &ui, Pvl *log) {
    try {
      // Get the DefFile
      QString sDefFile = "";
      QString sOutFile = "";
      Pvl pvlDefFile;
      if (ui.WasEntered("DEFFILE")) {
        sDefFile = ui.GetFileName("DEFFILE");
        sOutFile = ui.GetFileName("FLATFILE");
        pvlDefFile = Pvl(sDefFile);

        // Log the DefFile - Cannot log Object... only by Group
        for (int i=0; i<pvlDefFile.objects(); i++) {
          PvlObject pvlObj = pvlDefFile.object(i);
          for (int j=0; j<pvlObj.groups(); j++) {
            log->addGroup(pvlObj.group(j));
          }
        }

        // Verify DefFile comparing with the Template
        Pvl pvlTemplate("$ISISROOT/appdata/templates/cnetstats/cnetstats.def");
        Pvl pvlResults;
        pvlTemplate.validatePvl(pvlDefFile, pvlResults);
        if(pvlResults.objects() != 0 || pvlResults.groups() != 0 || pvlResults.keywords() != 0){
          for (int i=0; i<pvlResults.objects(); i++) {
            PvlObject pvlObj = pvlResults.object(i);
            for (int j=0; j<pvlObj.groups(); j++) {
              log->addGroup(pvlObj.group(j));
            }
          }
          QString sErrMsg = "Invalid Deffile\n";
          throw IException(IException::User, sErrMsg, _FILEINFO_);
        }
      }

      // Get the Image Stats File
      QString sImageFile= "";
      if (ui.WasEntered("CREATE_IMAGE_STATS") && ui.GetBoolean("CREATE_IMAGE_STATS")) {
        sImageFile = ui.GetFileName("IMAGE_STATS_FILE");
      }

      // Get the Point Stats File
      QString sPointFile="";
      if (ui.WasEntered("CREATE_POINT_STATS") && ui.GetBoolean("CREATE_POINT_STATS")) {
        sPointFile = ui.GetFileName("POINT_STATS_FILE");
      }

       // Get the original control net internalized
      Progress progress;
      // ControlNet cNet(ui.GetFileName("CNET"), &progress);

      Progress statsProgress;
      ControlNetFilter cNetFilter(&innet, serialNumFile, &statsProgress);

      // Log the summary of the input Control Network
      PvlGroup statsGrp;
      cNetFilter.GenerateControlNetStats(statsGrp);
      log->addGroup(statsGrp);

      // Run Filters using Deffile
      if (ui.WasEntered("DEFFILE")) {
        cNetFilter.SetOutputFile(sOutFile);
        ReadDefFile(cNetFilter, pvlDefFile);
      }

      // Run Image Stats
      if (ui.WasEntered("CREATE_IMAGE_STATS") && ui.GetBoolean("CREATE_IMAGE_STATS")) {
        cNetFilter.GenerateImageStats();
        cNetFilter.PrintImageStats(sImageFile);
      }

      // Run Point Stats
      if (ui.WasEntered("CREATE_POINT_STATS") && ui.GetBoolean("CREATE_POINT_STATS")) {
        cNetFilter.GeneratePointStats(sPointFile);
      }
    } // REFORMAT THESE ERRORS INTO ISIS TYPES AND RETHROW
    catch(IException &) {
      throw;
    }
  }