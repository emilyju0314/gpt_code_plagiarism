void trace::MemoryTraceAnalyzer::kernel_level_overlapped_global_memory(int segmentSize_pow2) {
	using namespace ir;
	using namespace std;
	
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
				<< "individual accesses requried for computing " 
				<< "kernel global memory overlaps.";
			throw hydrazine::Exception( error.str() );
		}
		
		std::ifstream stream( kernel->path.c_str() );
		boost::archive::text_iarchive archive( stream );
		
		if (!stream.is_open()) {
			throw hydrazine::Exception(
				"Failed to open MemoryTrace kernel trace file " 
				+ kernel->path );
		}
		
		PTXU64 globalWorkingSetSize = (header.global_max_address - header.global_min_address);
		PTXU64 globalSegmentCount = (globalWorkingSetSize >> segmentSize_pow2) +
			((globalWorkingSetSize & ((1<<segmentSize_pow2)-1)) ? 1 : 0);
		PTXS32 *globalSegmentOwners = new PTXS32[globalSegmentCount];
		
		for (PTXU64 n = 0; n < globalSegmentCount; n++) {
			globalSegmentOwners[n] = -1;
		}

		PTXU64 global_Lds = 0, 
			global_crossCta_Lds = 0,
			global_Sts = 0,
			global_OOB = 0;

		PTXU64 observed_min_address = 0, 
			observed_max_address = 0;
		
		while (true) {
			try {
				MemoryTraceGenerator::Event event;
				archive >> event;
				
				if (event.addressSpace == PTXInstruction::Global) {
					PTXS32 ctaID = event.ctaX + event.ctaY * header.blockDimX + 
						event.ctaZ * (header.blockDimX * header.blockDimY);

					for (MemoryTraceGenerator::AccessVector::const_iterator acc_it = event.accesses.begin();
						acc_it != event.accesses.end(); ++acc_it) {
					
						PTXU64 segmentNumber = ((acc_it->address - header.global_min_address) >> segmentSize_pow2);

						if (!observed_min_address || acc_it->address < observed_min_address) {
							observed_min_address = acc_it->address;
						}
						if (!observed_max_address || acc_it->address > observed_max_address) {
							observed_max_address = acc_it->address;
						}
						
						if (segmentNumber < globalSegmentCount) {
							if (event.opcode == PTXInstruction::St) {
								for (PTXU64 n = 0; n < (PTXU64)acc_it->size; n++) {
									PTXU64 seg = (((acc_it->address + n) - header.global_min_address) >> segmentSize_pow2);
									globalSegmentOwners[seg] = ctaID;
								}
								++global_Sts;
							}
							else if (event.opcode == PTXInstruction::Ld) {
								if (globalSegmentOwners[segmentNumber] >= 0 && globalSegmentOwners[segmentNumber] != ctaID) {
									// event of interest
									//
									// record statistics
									++global_crossCta_Lds;
								}
								++global_Lds;
							}
						}
						else {
							// bad news
							++ global_OOB;
						}
					}
				}
			}
			catch( const boost::archive::archive_exception& e ) {
				break;			
			}
		}
		
		delete [] globalSegmentOwners;

		cout << "\nKernel " << kernel->name << "\n";
		cout << " path: " << kernel->path << "\n";
		cout << " module: " << kernel->module << "\n";
		cout << "     global addr range: 0x" << hex << header.global_min_address << " - 0x" << header.global_max_address << dec << "\n";
		cout << "      working set size: " << (header.global_max_address - header.global_min_address) << " bytes\n";
		cout << " segments of " << (1<<segmentSize_pow2) << " bytes: " << globalSegmentCount << "\n";
		cout << "       global OOB refs: " << global_OOB << "\n";
		cout << "   global stored words: " << global_Sts << "\n";
		cout << "     global load words: " << global_Lds << "\n";
		cout << "      x-cta load words: " << global_crossCta_Lds << "\n";
	}
}