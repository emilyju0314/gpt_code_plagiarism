int runsavedcalib()
{

	auto modelfile = setpath + "model-dome.yaml";
	cout << "Loading saved calibration data: " << modelfile << endl;
	// Load PhotometricStereo algorithm from settings file
	
	try {
		auto pstereo = gs::LoadPhotometricStereo(modelfile);

        // Run pstereo algorithm on a scan
		runpstereo(pstereo.get());

	} catch (gs::Exception& e) {
		cout << "Exception: " << e.error() << endl;
	}

	return 0;
}