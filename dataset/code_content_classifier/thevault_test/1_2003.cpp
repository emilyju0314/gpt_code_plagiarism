void util::KernelExtractorDriver::bindKernel(
	CUresult result, 
	CUmodule module,
	CUfunction function, 
	const char *name) {

	ModuleNameMap::const_iterator mod_it = moduleNameMap.find(module);
	if (mod_it != moduleNameMap.end()) {
		std::pair<std::string,std::string> fname(mod_it->second, name);
		functionNameMap[function] = fname;
	}
}