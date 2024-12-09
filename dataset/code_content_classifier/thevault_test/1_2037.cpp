void trace::MemoryTraceAnalyzer::application_level_overlapped_global_memory(int segmentSize_pow2) {
	CTAData data;
	using namespace std;
	
	ApplicationMap applications = GetApplications(_kernels, false);
	
	for( ApplicationMap::iterator app = applications.begin(); 
		app != applications.end(); ++app )
	{
		ir::PTXU64 minAddress = -1;
		ir::PTXU64 maxAddress = 0;
	
		for( vector< KernelData >::const_iterator 
			kernel = app->second.kernels.begin(); 
			kernel != app->second.kernels.end(); ++kernel)	{
			minAddress = std::min( minAddress, 
				kernel->header.global_min_address );
			maxAddress = std::max( maxAddress, 
				kernel->header.global_min_address );
		}
	
		data.initialize( maxAddress - minAddress, minAddress, segmentSize_pow2 );
		application_overlapped(app->second, segmentSize_pow2);
	}

}