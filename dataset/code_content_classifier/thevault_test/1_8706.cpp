int runcalibration()
{

    // Create list of calibration targets
    std::vector<std::shared_ptr<gs::CalibrationTarget>> targets;

    // We have 3 scans of the calibration target at different positions
    // we will add them all to the list of calibration targets
    for (int i = 0; i < 3; ++i) {
        auto scanfolder = fs::canonicalize(setpath + "FingerData/scan00" + std::to_string(i+1));
        auto target     = gs::BgaTarget::create(scanfolder);
        targets.push_back(target);
    }

    auto start = std::chrono::system_clock::now();
	
    cout << "Running calibration algorithm..." << endl;

    auto pstereo = gs::CalibratePhotometricStereo(targets, gs::Version());

    std::chrono::duration<double> readtime = std::chrono::system_clock::now() - start;
    
    cout << "calibration took " << readtime.count() << " seconds" << endl;

    // Save the calibration data to a file
    // Only supported file format is YAML
    pstereo->save(setpath + "FingerData/fingerdemo-calibration.yaml", gs::Format::YAML);

    return 0;
}