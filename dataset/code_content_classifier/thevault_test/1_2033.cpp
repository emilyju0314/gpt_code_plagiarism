void MemoryTraceAnalyzer::histogram(std::string prefix, int bin_size_pow2) {
		using namespace std;
		typedef std::map< ir::PTXU64, ir::PTXU64 > Histogram; 

		map< ir::PTXInstruction::AddressSpace, ir::PTXU64 > addressMask;
		map< ir::PTXInstruction::AddressSpace, Histogram > histograms;
		for (unsigned int i = 0; i < (unsigned int)spaces.size(); i++) {
			// cglspt
			ir::PTXInstruction::AddressSpace 
				space = ir::PTXInstruction::AddressSpace_Invalid;
			switch (spaces[i]) {
				case 'c': space = ir::PTXInstruction::Const; break;
				case 'g': space = ir::PTXInstruction::Global; break;
				case 'l': space = ir::PTXInstruction::Local; break;
				case 's': space = ir::PTXInstruction::Shared; break;
				case 'p': space = ir::PTXInstruction::Param; break;
				case 't': space = ir::PTXInstruction::Texture; break;
				default:
					break;
			}
			histograms[space] = Histogram();
		}

		// enables of masking address bits
		addressMask[ir::PTXInstruction::Const] = ~(0);
		addressMask[ir::PTXInstruction::Global] = ~(0);
		addressMask[ir::PTXInstruction::Local] = ~(0);
		addressMask[ir::PTXInstruction::Shared] = (16384-1);
		addressMask[ir::PTXInstruction::Param] = ~(0);
		addressMask[ir::PTXInstruction::Texture] = ~(0);		
		
		// iterates over kernels in archive
		for( KernelVector::const_iterator kernel = _kernels.begin(); 
			kernel != _kernels.end(); ++kernel)	{
						
			// open the kernel's archive and visit every ld/st instruction
			std::ifstream hstream( kernel->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
		
			MemoryTraceGenerator::Header header;
		
			harchive >> header;
			assert( header.format == TraceGenerator::MemoryTraceFormat );
			hstream.close();	
		
			if( header.headerOnly )
			{
				std::stringstream error;
				error << "Trace for Kernel " << kernel->name 
					<< " was generated without support for recording " 
					<< "individual accesses requried for histogram generation.";
				throw hydrazine::Exception( error.str() );
			}
			
			std::ifstream stream( kernel->path.c_str() );
			boost::archive::text_iarchive archive( stream );
						
			for(; true; ) {
				try {
					MemoryTraceGenerator::Event event;
					archive >> event;

					if (histograms.find(event.addressSpace) != histograms.end()) {
						Histogram &hist = histograms[event.addressSpace];

						for (MemoryTraceGenerator::AccessVector::iterator acc_it = event.accesses.begin();
							acc_it != event.accesses.end(); ++acc_it) {

							ir::PTXU64 address = (acc_it->address & addressMask[event.addressSpace]);

							ir::PTXU64 binNumber = ((address >> bin_size_pow2) << bin_size_pow2);
							if (hist.find(binNumber) == hist.end()) {
								hist[binNumber] = 1;
							}
							else {
								++hist[binNumber];
							}

						}	// end for(accesses)
					}
				}
				catch( const boost::archive::archive_exception& e ) {
					break;			
				}
			}	// end for(events)

		}	// end for(kernels)

		// now emit the histogram
		for (map< ir::PTXInstruction::AddressSpace, Histogram >::iterator hist_it = histograms.begin();
			hist_it != histograms.end(); ++hist_it) {

			string filename = prefix + "_" + ir::PTXInstruction::toString(hist_it->first) + ".csv";
			std::ofstream file(filename.c_str());

			for (Histogram::iterator h_it = hist_it->second.begin(); h_it != hist_it->second.end(); ++h_it) {
				file << "0x" << hex << h_it->first << "," << dec << h_it->second << "\n";
			}
			hist_it->second.clear();
		}
	}