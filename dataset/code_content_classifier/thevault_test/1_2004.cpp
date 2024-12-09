void util::KernelExtractorDriver::bindTexture(
	CUresult result, 
	CUmodule module, 
	CUtexref texture, 
	const char *name) {
	
	ModuleNameMap::const_iterator mod_it = moduleNameMap.find(module);
	if (mod_it != moduleNameMap.end()) {
		std::pair<std::string,std::string> fname(mod_it->second, name);
		textureNameMap[texture] = fname;
	}
}