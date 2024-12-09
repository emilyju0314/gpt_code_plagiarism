void writePoints(const UserInterface &ui, QList<PvlGroup*> camPoints, Pvl *log) {
    // Progress should increment for each point we process
    Progress prog;
    prog.SetMaximumSteps(camPoints.size());
    QString outFile;
    // Get user params from ui
    if (ui.WasEntered("TO")) {
      outFile = FileName(ui.GetFileName("TO")).expanded();
    }
    bool append = ui.GetBoolean("APPEND");
    QString fileFormat = ui.GetString("FORMAT");
    PvlGroup *point = NULL;

    for (int p = 0; p < camPoints.size(); p++) {
        bool fileExists = FileName(outFile).fileExists();

      prog.CheckStatus();
      point = camPoints[p];

      // Remove units on look direction vectors
      point -> findKeyword("LookDirectionBodyFixed").setUnits("");
      point -> findKeyword("LookDirectionJ2000").setUnits("");
      point -> findKeyword("LookDirectionCamera").setUnits("");

      // write to output file
      if (ui.WasEntered("TO")) {
        // Write the pvl group out to the file
        if (fileFormat == "PVL") {
          Pvl temp;
          temp.setTerminator("");
          temp.addGroup((*point));

         // we don't want to overwrite successive points in outfile
          if (append || p > 0) {
            temp.append(outFile);
          }
          else {
            temp.write(outFile);
          }
       }
        // Create a flatfile from PVL data
        // The flatfile is comma delimited and can be imported into Excel
        else {
          ofstream os;
          bool writeHeader = false;
          if (append || p > 0) {
          os.open(outFile.toLatin1().data(), ios::app);
            if (!fileExists) {
              writeHeader = true;
            }
          }
          else {
            os.open(outFile.toLatin1().data(), ios::out);
            writeHeader = true;
          }

          if (writeHeader) {
            for (int i = 0; i < (*point).keywords(); i++) {
              if ((*point)[i].size() == 3) {
                os << (*point)[i].name() << "X,"
                << (*point)[i].name() << "Y,"
                << (*point)[i].name() << "Z";
              }
              else {
                os << (*point)[i].name();
              }

              if (i < point->keywords() - 1) {
                os << ",";
              }
            }
            os << endl;
          }



          for (int i = 0; i < (*point).keywords(); i++) {
            if ((*point)[i].size() == 3) {
              os << (QString)(*point)[i][0] << ","
              << (QString)(*point)[i][1] << ","
              << (QString)(*point)[i][2];
            }
            else {
              os << (QString)(*point)[i];
            }

            if (i < (*point).keywords() - 1) {
              os << ",";
            }
          }
          os << endl;
        }
      }

      // No output file specified
      else {
        // don't log data -
        if (ui.GetString("FORMAT") == "FLAT") {
          string msg = "Flat file must have a name.";
          throw IException(IException::User, msg, _FILEINFO_);
        }
      }

      // we still want to output the results
      log->addGroup((*point));
      delete point;
      point = NULL;
    }
    prog.CheckStatus();
  }