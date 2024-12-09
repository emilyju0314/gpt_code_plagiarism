void runCalibrationFromImagePaths()
{
//	const double pitchmm  = 0.4;
//	const double radiusmm = 0.15625;
	const double resolution = 0.007812500000000002;

	// List of BGA Targets
	std::vector<std::shared_ptr<gs::CalibrationTarget>> targets;
	for (int i = 0; i < 4; ++i) {
		// Path to scan folder
		auto scanp = string("../../../testdata/BGA-00") + std::to_string(i+1);

		// Now create BGAs from scans
		auto target = gs::BgaTarget::create( scanp );

		targets.push_back(target);
	}

	cout << "Run calibration algorithm..." << endl;
    auto pstereo = gs::CalibratePhotometricStereo(targets, resolution, gs::Version());

	// Save calibration file as model.yaml
	pstereo->save("../../../testdata/testmodel.yaml", gs::Format::YAML);
}