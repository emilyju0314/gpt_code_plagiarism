void runCalibrationFromImagePaths()
{
  const double resolution = 0.0295297735479;

   // List of BGA Targets
   std::vector<std::shared_ptr<gs::CalibrationTarget>> targets;
   for (int i = 0; i < 3; ++i) {

     auto scanp = fs::canonicalize(setpath + "FingerData/scan00" + std::to_string(i+1));
	
     // Now create BGAs from scans
     auto target = gs::BgaTarget::create( scanp );

     targets.push_back(target);
   }

    cout << "Run calibration algorithm..." << endl;
    auto pstereo = gs::CalibratePhotometricStereo(targets, resolution, gs::Version());

    // Save calibration file as model.yaml
    pstereo->save(setpath+"FingerData/testmodel.yaml", gs::Format::YAML);
}