size_t trace::PerformanceBoundGenerator::computeSharedDemand(const trace::TraceEvent &event, 
	int * conflicts) {
	typedef std::map< size_t, size_t > SharedBankCounter;
	size_t bytes = 0;
	*conflicts = 0;
		
	if ((event.instruction->opcode == ir::PTXInstruction::Ld || 
		event.instruction->opcode == ir::PTXInstruction::St) &&
		event.instruction->addressSpace == ir::PTXInstruction::Shared) {
	
		size_t end = 0xffffffff;
		std::vector< size_t > addresses;
		for (int n = 0, tid = 0; tid < (int)event.active.size(); ++tid) {
			if (event.active[tid]) {
				addresses.push_back(event.memory_addresses[n++]);
			}
			else {
				addresses.push_back(end);
			}
		}
		
		for (int tid = 0; tid < (int)event.active.size(); tid += 16) {		
			SharedBankCounter bankAddresses;
			for (int t = 0; t < 16; t++) {
				size_t addr = addresses[tid + t];
				if (addr != end) {
					size_t base = (addr & 0x3c);
					SharedBankCounter::iterator bank = bankAddresses.find(base);
					if (bank == bankAddresses.end()) {
						bankAddresses[base] = addr;
					}
					else {
						if (bank->second != addr) {
							++ *conflicts;
						}
					}
					
					bytes += event.memory_size;
				}
			}
		}
	}

	return bytes;
}