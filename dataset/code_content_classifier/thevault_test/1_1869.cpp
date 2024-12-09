void trace::ConvergenceGenerator::finish() {

	// aggregate entry statistics
	for (OperationCounterMap::const_iterator op_it = counterMap.begin();
		op_it != counterMap.end(); ++op_it) {
		
		if (op_it->first != "entry" && op_it->first != "exit") {
			counterMap["entry"] += op_it->second;
		}
	}
	
	boost::filesystem::path path( database );
	path = path.parent_path();
	path = boost::filesystem::system_complete( path );
		
	std::fstream resultFile(
		TraceConfiguration::Singleton.convergence.logfile.c_str(), 
		std::ios_base::out | std::ios_base::app);

	write(resultFile);
	
	if (TraceConfiguration::Singleton.convergence.dot) {
		writeCFG();
	}
}