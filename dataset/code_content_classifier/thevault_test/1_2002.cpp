void util::KernelExtractorDriver::loadModule(
	CUresult result, CUmodule module, 
	const char *ptxImage, 
	const char *name) {
	
	std::stringstream ss;
	ss << "module" << moduleNameMap.size();
	std::string modName = ss.str();
	
	if (name) {
		modName = name;	
	}
	
	if (ptxImage) {
		std::stringstream fss;
		fss << modName << ".ptx";
		state.modules[modName]->name = modName;
		state.modules[modName]->ptx = fss.str();
		std::ofstream file(fss.str());
		file << ptxImage;
	}
	else if (name) {
		modName = name;
		state.modules[modName]->name = modName;
		state.modules[modName]->ptx = name;
	}
	moduleNameMap[module] = modName;
}