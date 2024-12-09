int runpstereo(gs::PhotometricStereo *pstereo)
{
	string scanfile = setpath + "R513-500/scan.yaml";

	cout << "Running photometric stereo algorithm on " << scanfile << endl;

	// Load a scan from the scan file
	
	auto scan = gs::LoadScanFromYAML(scanfile, gs::DefaultAnalysisManager());

	// Load images from scan
	auto images = gs::util::LoadImages(scan->imagePaths());

	cout << "Loaded " << images.size() << " images" << endl;
	if (images.size() == 0)
		return 1;

	// Do surface normal reconstruction
	auto nrm = pstereo->nonlinearNormalMap(images, pstereo->roi());

	// Integrate normals into heightmap
	cout << "Integrating surface normals..." << endl;
	auto poisson = gs::CreateIntegrator(gs::Version());
	auto heightmap = poisson->integrateNormalMap(nrm, pstereo->resolution());

	// Save surface as TMD
	string out1 = setpath + "R513-500/output.tmd";
	cout << "Saving heightmap: " << out1 << endl;
	gs::util::WriteTMD(out1, heightmap, pstereo->resolution(), 0.0, 0.0);


	// Save normal map
	string out2 = setpath + "R513-500/output_nrm.png";
	cout << "Saving normal map: " << out2 << endl;
	gs::util::WriteNormalMap(out2, nrm, 16);

	return 0;
}