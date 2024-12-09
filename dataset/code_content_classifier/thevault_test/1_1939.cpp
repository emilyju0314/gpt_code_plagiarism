void trace::WarpSynchronousGenerator::outputHotPaths(int warpSize) {
	const SynchronousInstructionCounter & counter = warpCounters[warpSize];

	DotFormatter formatter;
	formatter.warpSize = warpSize;
	formatter.traceGenerator = this;

	std::map< int, TargetCounter >::const_iterator target_it;
	
	formatter.maxEvents = 0;
	for (target_it = counter.counterTargets.begin(); target_it != counter.counterTargets.end(); 
		++target_it) {
		//blockColors[branchTargetsToBlock[target_it->first]] = 0;
		if (formatter.maxEvents < target_it->second.events) {
			formatter.maxEvents = target_it->second.events;
		}
		if ( (!formatter.minEvents && target_it->second.events) || (target_it->second.events && 
			target_it->second.events < formatter.minEvents)) {
			formatter.minEvents = target_it->second.events;
		}
	}
	if (formatter.maxEvents) {
		for (target_it = counter.counterTargets.begin(); target_it != counter.counterTargets.end(); 
			++target_it) {
			//blockColors[branchTargetsToBlock[target_it->first]] = color;
			formatter.blockCounter[ branchTargetsToBlock[target_it->first] ] = target_it->second;
		}
	}

	std::stringstream ss;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path = boost::filesystem::system_complete( path );
	ss << path.string() << "/" << _entry.program << "_" << _entry.name << "_" 
		<< _counter << "_ws" << warpSize << "_hotpath.dot";
	
	std::string filename = ss.str();

	report(" outputHotPaths(ws: " << warpSize << ", filename = " << filename << ")");

	std::ofstream cfgFile(filename.c_str());
	cfgFile << "/*\n";
	cfgFile << "     kernel: " << " kernel-name " << "\n";
	cfgFile << "  warp size: " << warpSize << "\n";
	cfgFile << "*/\n";

	controlFlowGraph->write(cfgFile, formatter);
}