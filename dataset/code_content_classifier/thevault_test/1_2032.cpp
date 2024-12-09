ApplicationMap GetApplications(MemoryTraceAnalyzer::KernelVector _kernels, bool filter) {
		using namespace std;
		
		ApplicationMap applications;

		for(MemoryTraceAnalyzer::KernelVector::const_iterator kernel = _kernels.begin(); 
			kernel != _kernels.end(); ++kernel)	{
		
			// open the kernel's archive and visit every ld/st instruction
			std::ifstream hstream( kernel->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
		
			MemoryTraceGenerator::Header header;
		
			harchive >> header;
			assert( header.format == TraceGenerator::MemoryTraceFormat );
			hstream.close();	
		
			KernelData data;
			data.kernel = *kernel;
			data.header = header;
		
			applications[ kernel->program ].kernels.push_back( data );
			applications[ kernel->program ].name = kernel->program;
		}

		if (filter) {
			ApplicationMap applications_out;	
			for (ApplicationMap::iterator fi = applications.begin(); 
				fi != applications.end(); ++fi) {
				bool print = false;
				map< string, int > kernelCalls;
				for (int j = 0; j < (int)fi->second.kernels.size(); j++) {
					string name = fi->second.kernels[j].kernel.name;
					if (kernelCalls.find(name) == kernelCalls.end()) {
						kernelCalls[name] = 1;
					}
					else {
						print = true;
						kernelCalls[name]++;
					}
				}
				if (print) {
					applications_out.insert( *fi );
				}
			}
			return applications_out;
		}

		return applications;
	}