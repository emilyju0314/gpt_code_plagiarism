void trace::InstructionTraceGenerator::initialize(
	const executive::ExecutableKernel& kernel) {
	//
	// initialize kernel entry
	//
	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = InstructionTraceFormat;

	std::string name = kernel.name;

	if( name.size() > 20 ) name.resize( 20 );

	std::stringstream stream;
	stream << _entry.format << "_" << _counter++;

	boost::filesystem::path path( database );
	
	path = path.parent_path();
	path /= _entry.program + "_" + name + "_" + stream.str() + ".header";
	path = boost::filesystem::system_complete( path );
	
	_entry.header = path.string();
	
	_header.format = InstructionTraceFormat;
		
	// static counts
	const executive::EmulatedKernel &emuKernel = 
		static_cast<const executive::EmulatedKernel &>(kernel);
		
	_header.blockDim = emuKernel.blockDim();
	_header.gridDim = emuKernel.gridDim();
	
	threadCount = _header.blockDim.x * _header.blockDim.y * _header.blockDim.z;

	instructionCounter.clear();	
	for (executive::EmulatedKernel::PTXInstructionVector::const_iterator instr_it = 
		emuKernel.instructions.begin();
		instr_it != emuKernel.instructions.end(); ++instr_it ) {
	
		const ir::PTXInstruction & instr = *instr_it;
		
		FunctionalUnit fu = getFunctionalUnit(instr);
		if (instructionCounter.find(fu) == instructionCounter.end()) {
			OpcodeCountMap opMap;
			instructionCounter[fu] = opMap;
		}
		if (instructionCounter[fu].find(instr.opcode) == instructionCounter[fu].end()) {
			InstructionCounter counter;
			instructionCounter[fu][instr.opcode] = counter;
		}
		
		++instructionCounter[fu][instr.opcode].static_count;
	}
}