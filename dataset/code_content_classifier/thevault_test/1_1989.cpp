void trace::SharedComputationAnalyzer::shared_computation(bool machine_readable) {
	using namespace ir;
	using namespace std;
	
	ostream &out = cout;
	
	PTXU64 agg_storeCount = 0;
	PTXU64 agg_loadCount = 0;
	PTXU64 agg_crossLdCount = 0;
	PTXU64 agg_Instr = 0;

	out << "sharedComputation = (\n";
	
	// iterates over kernels in archive
	for( KernelMap::const_iterator application = _kernels.begin(); 
		application != _kernels.end(); ++application ) {

		PTXU64 app_storeCount = 0;
		PTXU64 app_loadCount = 0;
		PTXU64 app_crossLdCount = 0;
		PTXU64 app_Instr = 0;
		
		for( KernelVector::const_iterator kernel = application->second.begin(); 
			kernel != application->second.end(); ++kernel)	{
		
			std::ifstream hstream( kernel->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
	
			SharedComputationGenerator::Header header;
	
			harchive >> header;
			assert( header.format == TraceGenerator::SharedComputationTraceFormat );
		
			hstream.close();	
	
			agg_storeCount += header.storeSharedCount;
			agg_loadCount += header.loadSharedCount;
			agg_crossLdCount += header.crossThreadLds;
			agg_Instr += header.dynamic_instructions;

			app_storeCount += header.storeSharedCount;
			app_loadCount += header.loadSharedCount;
			app_crossLdCount += header.crossThreadLds;
			app_Instr += header.dynamic_instructions;

			if (machine_readable) {
				out << "\t('" << kernel->name << "' , " << header.storeSharedCount << " , " 
					<< header.loadSharedCount << " , " << header.crossThreadLds
					<< " , " << header.dynamic_instructions << "),\n";
			}
			else {
				out << "Kernel " << kernel->name << "\n";
				out << "           st.shared count: " << header.storeSharedCount << "\n";
				out << "           ld.shared count: " << header.loadSharedCount << "\n";
				out << "  x-thread ld.shared count: " << header.crossThreadLds << "\n";
				if (header.loadSharedCount) {
					out << "                fraction: " 
						<< (double)header.crossThreadLds 
						/ (double)header.loadSharedCount << "\n";
				}
			}
		}	// end for(kernels)

		if (machine_readable) {
			// (kernelName, storeCount, loadCount, xCtaLdCount, dynamic_instructions) = result
			out << "\t( '" << application->first << "' , " << app_storeCount 
				<< " , " << app_loadCount << " , " << app_crossLdCount 
				<< " , " << app_Instr << ")\n";
		}
		else {
			out << "\n" << application->first << "Aggregate:\n";
			out << "  st.shared count: " << app_storeCount << "\n";
			out << "  ld.shared count: " << app_loadCount << "\n";
			out << "   x-thread count: " << app_crossLdCount << "\n";
			if (app_loadCount) {
				out << "         fraction: " << (double)app_crossLdCount 
					/ (double)app_loadCount << "\n";
			}
		}
	
	}
	
	if (machine_readable) {
		// (kernelName, storeCount, loadCount, xCtaLdCount, dynamic_instructions) = result
		out << "\t( 'aggregate' , " << agg_storeCount << " , " << agg_loadCount << " , " << agg_crossLdCount 
			<< " , " << agg_Instr << ")\n";
		out << ")\n\n";
	}
	else {
		out << "\nAggregate:\n";
		out << "  st.shared count: " << agg_storeCount << "\n";
		out << "  ld.shared count: " << agg_loadCount << "\n";
		out << "   x-thread count: " << agg_crossLdCount << "\n";
		if (agg_loadCount) {
			out << "         fraction: " << (double)agg_crossLdCount / (double)agg_loadCount << "\n";
		}
	}
}