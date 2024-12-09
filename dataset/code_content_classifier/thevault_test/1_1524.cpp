void TranslateHrscLabels(Pvl &inLabels, Pvl &outLabel) {

  // Get the directory where the translation tables are.
  QString transDir = "$ISISROOT/appdata/translations/";

  // Translate the Instrument group
  FileName transFile(transDir + "MexHrscInstrument.trn");
  PvlToPvlTranslationManager instrumentXlater(inLabels, transFile.expanded());
  instrumentXlater.Auto(outLabel);

  // Remove 'Z' from times
  QString startTime = outLabel.findGroup("Instrument", Pvl::Traverse)["StartTime"][0];
  startTime = startTime.mid(0, startTime.size() - 1);
  outLabel.findGroup("Instrument", Pvl::Traverse)["StartTime"] = startTime;

  QString stopTime = outLabel.findGroup("Instrument", Pvl::Traverse)["StopTime"][0];
  stopTime = stopTime.mid(0, stopTime.size() - 1);
  outLabel.findGroup("Instrument", Pvl::Traverse)["StopTime"] = stopTime;

  // Translate the BandBin group
  transFile  = transDir + "MexHrscBandBin.trn";
  PvlToPvlTranslationManager bandBinXlater(inLabels, transFile.expanded());
  bandBinXlater.Auto(outLabel);

  // Translate the Archive group
  transFile  = transDir + "MexHrscArchive.trn";
  PvlToPvlTranslationManager archiveXlater(inLabels, transFile.expanded());
  archiveXlater.Auto(outLabel);

  // Translate the Kernels group
  transFile  = transDir + "MexHrscKernels.trn";
  PvlToPvlTranslationManager kernelsXlater(inLabels, transFile.expanded());
  kernelsXlater.Auto(outLabel);

}