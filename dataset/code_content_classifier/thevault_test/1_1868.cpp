void trace::ConvergenceGenerator::writeCFG() {

	ConvergenceFormatter formatter(this);
	
	std::stringstream ss;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path = boost::filesystem::system_complete( path );
	ss << path.string() << "/" << _entry.program << "_" << _entry.name << "." 
		<< _counter << ".convergence.dot";
	
	std::string filename = ss.str();
	
	ir::ControlFlowGraph *controlFlowGraph = const_cast<ir::ControlFlowGraph*>(kernel->cfg());
	std::ofstream cfgFile(filename.c_str());
	cfgFile << "/*\n";
	cfgFile << "     kernel: " << kernel->name << "\n";
	cfgFile << "*/\n";

	controlFlowGraph->write(cfgFile, formatter);
	cfgFile.close();	
	
	if (TraceConfiguration::Singleton.convergence.render) {
		std::stringstream ss;		
		ss << "dot -Tpdf -o " << path.string() << "/" << _entry.program << "_" << _entry.name << "." << _counter 
			<< ".convergence.pdf " << filename;
		if (system(ss.str().c_str()) != 0) {
			report("system(" << ss.str() << ") failed");
		}
	}
}