int runcalibration()
{

	// Create list of calibration targets
    std::vector<std::shared_ptr<gs::CalibrationTarget>> targets;

    // We have 4 scans of the calibration target at different positions
    // we will add them all to the list of calibration targets
    for (int i = 0; i < 4; ++i) {
        auto scanfolder = fs::canonicalize(setpath + "BGA-00" + std::to_string(i+1));
        auto target     = gs::BgaTarget::create(scanfolder);
        targets.push_back(target);
    }

    // It's recommended, but not required, to add a scan of a flat plate to the 
    // list of calibration targets
	auto flatp = fs::canonicalize(setpath + "Flat-001");
    auto flat = gs::FlatTarget::create(flatp);
    targets.push_back(flat);

	auto start = std::chrono::system_clock::now();
	
	cout << "Running calibration algorithm..." << endl;

	auto pstereo = gs::CalibratePhotometricStereo(targets, gs::Version());

	std::chrono::duration<double> readtime = std::chrono::system_clock::now() - start;
    
	cout << "calibration took " << readtime.count() << " seconds" << endl;

    // Save the calibration data to a file
    // Only supported file format is YAML
    pstereo->save(setpath + "demo-calibration.yaml", gs::Format::YAML);

	return 0;
}