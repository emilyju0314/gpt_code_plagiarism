vector<string> doscan(const string& foldername)
{
	string calibdir = setpath + "calib";
	
	vector<string> paths;
	for (int i = 0; i < 6; ++i) {
		paths.push_back(calibdir + "/image0" + std::to_string(i+1) + ".png");
	}
	return paths;
}