void trace::PerformanceBoundGenerator::finish() {

	// aggregate entry statistics
	for (OperationCounterMap::const_iterator op_it = counterMap.begin();
		op_it != counterMap.end(); ++op_it) {
		
		if (op_it->first != "entry" && op_it->first != "exit") {
			counterMap["entry"] += op_it->second;
		}
	}

	Formatter formatter(this);
	
	std::stringstream ss;
	
	for (OperationCounterMap::const_iterator opit = counterMap.begin(); opit != counterMap.end(); ++opit) {
		if (opit->second.instructions > formatter.maxEvents) {
			formatter.maxEvents = opit->second.instructions;
		}
	}
	
	if (outputFormat == Output_append_csv) {
	
		//
		// append kernel aggregate results
		//
		boost::filesystem::path path(database);
		path = path.parent_path();
		path = boost::filesystem::system_complete(path);
		ss << path.string() << "/performance-bound-results.txt";
		std::ofstream resultsFile(ss.str().c_str(), std::ios_base::app);
	
		const char *app = getenv("APPLICATION");
		const char *reconverge = getenv("RECONVERGE");
		
		app = (app ? app: "unknown-app");
		reconverge = (reconverge ? reconverge : "unknown-reconverge");
	
		// appliction, reconvergence method, kernel name, counter, warp instructions, dynamic scalar instructions, 
		resultsFile 
			<< app << ", " 
			<< reconverge
			<< _entry.name << ", " 
			<< _counter << ", "
			<< counterMap["entry"].warpInstructions << ", " 
			<< counterMap["entry"].instructions << ", "
			<< counterMap["entry"].stackVisitEnd << ", "
			<< counterMap["entry"].stackVisitMiddle << ", "
			<< counterMap["entry"].stackInsert << ", "
			<< counterMap["entry"].stackMerge << ", "
			<< (double)counterMap["entry"].stackDepth / (double)counterMap["entry"].warpInstructions << ", "
			<< counterMap["entry"].branchInstructions << ", "
			<< counterMap["entry"].stackVisitNodes << ", "
			<< counterMap["entry"].conservativeBranches << ", "
			<< counterMap["entry"].noopInstructions;
		
		resultsFile	<< std::endl;

	}
	else if (outputFormat == Output_dot) {
	
		boost::filesystem::path path( database );
		path = path.parent_path();
		path = boost::filesystem::system_complete( path );
		ss << path.string() << "/" << _entry.program << "_" << _entry.name << "_" 
			<< _counter << "_perf.dot";
	
		std::string filename = ss.str();
	
		ir::ControlFlowGraph *controlFlowGraph = const_cast<ir::ControlFlowGraph*>(kernel->cfg());
		std::ofstream cfgFile(filename.c_str());
		cfgFile << "/*\n";
		cfgFile << "     kernel: " << " kernel-name " << "\n";
		cfgFile << "*/\n";

		controlFlowGraph->write(cfgFile, formatter);
	}
}