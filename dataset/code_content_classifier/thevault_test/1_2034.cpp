void MemoryTraceAnalyzer::global_transactions(int warp_size, bool machine) {
		using namespace ir;
		
		std::ostream &out = std::cout;
		
		ir::PTXU64 global_instructions = 0;
		ir::PTXU64 global_halfwarps = 0;
		ir::PTXU64 global_transactions = 0;
		
		if (machine) {
			out << "memEfficiency = (\n";
		}

		ApplicationMap applications = GetApplications(_kernels, false);
		
		for( ApplicationMap::const_iterator application = applications.begin(); 
			application != applications.end(); ++application ) {

			ir::PTXU64 app_instructions = 0;
			ir::PTXU64 app_halfwarps = 0;
			ir::PTXU64 app_transactions = 0;
		
			for( KernelDataVector::const_iterator 
				kernel = application->second.kernels.begin(); 
				kernel != application->second.kernels.end(); ++kernel)	{
			
				MemoryTraceGenerator::Header header = kernel->header;
			
				ir::PTXU64 kernel_instructions 
					= header.global_instructions + header.texture_instructions;
				ir::PTXU64 kernel_halfwarps = header.halfwarps;
				ir::PTXU64 kernel_transactions = header.global_segments;
				ir::PTXU64 kernel_size = header.global_bytes + header.shared_bytes;
				ir::PTXU64 kernel_access_counter 
					= header.global_accesses + header.texture_accesses;
			
				global_instructions += kernel_instructions;
				global_halfwarps += kernel_halfwarps;
				global_transactions += kernel_transactions;

				app_instructions += kernel_instructions;
				app_halfwarps += kernel_halfwarps;
				app_transactions += kernel_transactions;
			
				if (machine) {
					// (kernelName, threadCount, instructions, halfwarps, transactions) = result
					out << "  ('" << kernel->kernel.name << "', " 
						<< header.thread_count << " , " 
						<< kernel_instructions << " , "
						<< kernel_halfwarps << " , " 
						<< kernel_transactions << "),\n";
				}
				else {
					// finish kernel
					out << "\nKernel " << kernel->kernel.name << "\n";
					out << "         thread count: " << header.thread_count << "\n";
					out << "  memory instructions: " << kernel_instructions << "\n"
							<< "            halfwarps: " << kernel_halfwarps << "\n"
							<< "         transactions: " << kernel_transactions << "\n";
					if (kernel_halfwarps) {
						out << "  average access size: " 
							<< (double)kernel_size / (double)kernel_access_counter 
							<< " bytes\n";
						out	<< "                  t/h: " 
							<< (double)kernel_transactions 
							/ (double)kernel_halfwarps << "\n";
					}
				}
			}
			// finished all kernels
			if (machine) {
				// (kernelName, threadCount, instructions, halfwarps, transactions) = result
				out << "  ('" << application->first << "', " << 0 << " , " 
					<< app_instructions << " , "
					<< app_halfwarps << " , " << app_transactions << "),\n";
			}
			else {
				out << "\nAggregate '" << application->first << "'results:\n";
				out << "            warp size: " << warp_size << "\n";
				out << "  memory instructions: " << app_instructions << "\n"
						<< "            halfwarps: " << app_halfwarps << "\n"
						<< "         transactions: " << app_transactions << "\n";
				if (app_halfwarps) {
					out << "                  t/h: " 
						<< (double)app_transactions 
						/ (double)app_halfwarps << "\n";
				}
			}
		}
				
		// finished all kernels
		if (machine) {
			// (kernelName, threadCount, instructions, halfwarps, transactions) = result
			out << "  ('SDK Average', " << 0 << " , " << global_instructions << " , "
				<< global_halfwarps << " , " << global_transactions << "),\n";
			out << ")\n\n";
		}
		else {
			out << "\nAggregate results:\n";
			out << "            warp size: " << warp_size << "\n";
			out << "  memory instructions: " << global_instructions << "\n"
					<< "            halfwarps: " << global_halfwarps << "\n"
					<< "         transactions: " << global_transactions << "\n";
			if (global_halfwarps) {
				out << "                  t/h: " 
					<< (double)global_transactions 
					/ (double)global_halfwarps << "\n";
			}
		}
	}