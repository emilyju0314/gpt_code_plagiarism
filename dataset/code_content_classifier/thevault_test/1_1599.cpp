void compareLabels(Pvl &matchLabel, Pvl &compareLabel) {
  // test of the ObservationId
   PvlGroup matchArchive = matchLabel.findGroup("Archive", Pvl::Traverse);
   PvlGroup compareArchive = compareLabel.findGroup("Archive", Pvl::Traverse);

   QString matchObsId = matchArchive["ObservationId"];
   QString compareObsId = compareArchive["ObservationId"];

   if (matchObsId != compareObsId) {
     QString msg = "Images not from the same observation";
     throw IException(IException::User, msg, _FILEINFO_);
   }

  // Test of the BandBin filter name
  PvlGroup matchBandBin = matchLabel.findGroup("BandBin", Pvl::Traverse);
  PvlGroup compareBandBin = compareLabel.findGroup("BandBin", Pvl::Traverse);
  QString matchFilter = matchBandBin["FilterName"];
  QString compareFilter = compareBandBin["FilterName"];

  if (matchFilter != compareFilter) {
    QString msg = "Images not the same filter";
    throw IException(IException::User, msg, _FILEINFO_);
  }
}