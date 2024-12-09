void trace::WarpSynchronousGenerator::initialize(const executive::ExecutableKernel& kernel) {

	const executive::EmulatedKernel & emuKernel = 
		static_cast<const executive::EmulatedKernel &>(kernel);

	//
	// initialize kernel header
	//
	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = TraceGenerator::WarpSynchronousTraceFormat;
	_entry.path = "";
	_entry.header = "";
	_entry.program = "";
	_entry.gridDim = kernel.gridDim();
	_entry.blockDim = kernel.blockDim();
		std::string name = kernel.name;

	// only look for complete uniformity
#if UNIFORM_CONTROL_FLOW_ONLY	
	warpSizes.clear();
	warpSizes.push_back(_entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z);
#endif
	
		
	if( name.size() > 20 ) {
		name.resize( 20 );
	}

	std::stringstream stream;
	stream << _entry.format << "_" << trace::WarpSynchronousGenerator::_counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= _entry.program + "_" + name + "_" + stream.str() + ".json";
	path = boost::filesystem::system_complete( path );
	
	_entry.header = path.string();

	//
	// identify all branches and create counters for them
	//
	std::map< int, int > branchPCs;
	std::map< int, std::vector<int> > targetPCs; // map's a target PC to list of branches jumping to it
	if (kernel.ISA == ir::Instruction::Emulated) {
		const executive::EmulatedKernel & emuKernel = 
			static_cast<const executive::EmulatedKernel &>(kernel);

		targetPCs[0].push_back(-1);	// first instruction gets a push

		executive::EmulatedKernel::PTXInstructionVector::const_iterator inst_it;

		int pc = 0;		
		for (inst_it = emuKernel.instructions.begin(); inst_it != emuKernel.instructions.end(); 
			++inst_it, ++pc) {
			const ir::PTXInstruction &inst = *inst_it;

			// complete per-instruction analysis 
			switch (inst.opcode) {
				case ir::PTXInstruction::Bra:
					branchPCs[pc] = inst.branchTargetInstruction;
					targetPCs[inst.branchTargetInstruction].push_back(pc);
					targetPCs[pc+1].push_back(pc);
					break;

				default:
					break;
			}
		}
	}

	// obtain control flow graph
	controlFlowGraph = emuKernel.cfg();
	branchTargetsToBlock = emuKernel.branchTargetsToBlock;
	for (std::map< int, std::string >::const_iterator it = branchTargetsToBlock.begin(); 
		it != branchTargetsToBlock.end(); ++it) {
		blockToBranchTarget[it->second] = it->first;
	}

	// for each warp size, initialize counters and create branch records
	warpCounters.clear();
	for (std::vector<int>::const_iterator ws_it = warpSizes.begin(); ws_it != warpSizes.end();
		++ws_it) {
		SynchronousInstructionCounter syncCounter;
		for (std::map<int,int>::const_iterator bra_it = branchPCs.begin(); 
			bra_it != branchPCs.end(); ++bra_it) {

			BranchCounter braCounter;
			braCounter.target = bra_it->second;
			syncCounter.counterBranches[bra_it->first] = braCounter;
		}
		for (std::map<int, std::vector<int> >::const_iterator targ_it = targetPCs.begin();
			targ_it != targetPCs.end(); ++targ_it) {
			TargetCounter targCounter;

			syncCounter.counterTargets[targ_it->first] = targCounter;
		}
		warpCounters[*ws_it] = syncCounter;
	}
}