void trace::SharedComputationGenerator::initialize(
	const executive::ExecutableKernel& kernel) {
	using namespace ir;

	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = SharedComputationTraceFormat;

	std::stringstream stream;
	stream << _entry.format << "_" << _counter++;

	std::string name = kernel.name;
		
	if( name.size() > 20 )
	{
		name.resize( 20 );
	}

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= name + "_" + stream.str() + ".trace";
	path = boost::filesystem::system_complete( path );

	_entry.path = path.string();

	path = path.parent_path();
	path /= name + "_" + stream.str() + ".header";
	path = boost::filesystem::system_complete( path );

	_entry.header = path.string();

	_header = Header();	
	_header.threadCount = kernel.maxThreadsPerBlock();

	if (sharedMemoryOwners) {
		delete [] sharedMemoryOwners;
	}

	_header.sharedMemorySize = 16384; //kernel->SharedMemorySize;

	blockId = 0; // for now - in real life, compute the actual blockId

	sharedMemoryOwners = new ir::PTXS32[_header.sharedMemorySize];
	for (PTXU32 i = 0; i < _header.sharedMemorySize; i++) {
		sharedMemoryOwners[i] = -1;
	}
	
	// examine kernel's basic blocks and look for ld.global <reg> ; st.shared [], <reg>; pairs. Add
	// st.shared [], reg program counters to mask set so these result in writing -1 to sharedMemoryOwners
	selectMaskedStSet(kernel);
}