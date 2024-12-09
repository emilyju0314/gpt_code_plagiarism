void util::ExtractedDeviceState::clear() {
	for (ModuleMap::iterator mod_it = modules.begin();
		mod_it != modules.end(); ++mod_it) {
		delete mod_it->second;
	}
	modules.clear();
	
	clearData();	
}