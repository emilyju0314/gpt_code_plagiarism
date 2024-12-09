int runsavedcalib()
{
  auto modelfile = setpath + "FingerData/finger-model.yaml";
  cout << "Loading saved calibration data: " << modelfile << endl;

  // Load PhotometricStereo algorithm from settings file
  // Run pstereo algorithm on scan
  try {
    auto pstereo = gs::LoadPhotometricStereo(modelfile);
    runpstereo(pstereo.get());
  } catch (gs::Exception& e) {
    cout << "Exception: " << e.error() << endl;
  }

  return 0;
}