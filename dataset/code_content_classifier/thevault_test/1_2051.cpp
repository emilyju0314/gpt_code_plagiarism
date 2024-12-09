void trace::SharedComputationGenerator::event(const TraceEvent & event) {
	using namespace ir;

	_header.dynamic_instructions += (PTXU64)event.active.count();

	if (event.instruction->opcode == PTXInstruction::St && 
		event.instruction->addressSpace == PTXInstruction::Shared) {

		PTXS32 threadID = 0;
		for (TraceEvent::U64Vector::const_iterator 
			addr_it = event.memory_addresses.begin(); 
			addr_it != event.memory_addresses.end(); ++addr_it, ++threadID) {

			for (; threadID < (PTXS32)_header.threadCount 
				&& !event.active[threadID]; ++threadID) {
				// do nothing - find the next active thread
			}
			if (threadID >= (PTXS32)_header.threadCount) {
				return;
			}
			
			++_header.storeSharedCount;

			PTXS32 threadIdentifier = threadID;
			if (maskedStSet.find(event.PC) != maskedStSet.end()) {
				threadIdentifier = -1;
			}
			
			PTXU64 baseAddress = *addr_it;
			for (PTXU64 offset = 0; 
				offset < (PTXU64)event.memory_size; offset++) {
				PTXU64 address = (baseAddress + offset) & SharedMemoryMask;
				if (address < _header.sharedMemorySize) {
					sharedMemoryOwners[address] = threadIdentifier;
				}
				else {
					++_header.storeOutOfBoundsAccesses;
				}
			}
		}		
	}
	else if (event.instruction->opcode == PTXInstruction::Ld && 
		event.instruction->addressSpace == PTXInstruction::Shared) {

		PTXS32 threadID = 0;
		for (TraceEvent::U64Vector::const_iterator 
			addr_it = event.memory_addresses.begin(); 
			addr_it != event.memory_addresses.end(); ++addr_it, ++threadID) {

			for (; threadID < (PTXS32)_header.threadCount 
				&& !event.active[threadID]; ++threadID) {
				// do nothing - find the next active thread
			}
			if (threadID >= (PTXS32)_header.threadCount) {
				return;
			}
			++_header.loadSharedCount;

			PTXU64 address = (*addr_it & SharedMemoryMask);
			if (address < _header.sharedMemorySize) {
				PTXS32 owningThread = sharedMemoryOwners[address];
				if (owningThread >= 0 && owningThread != threadID) {
					++_header.crossThreadLds;
				}
			}
			else {
				// bad news
				++_header.loadOutOfBoundsAccesses;
			}
		}

		if (event.memory_addresses.size()) {
			++_header.sharedLoads;
		}
	}
}