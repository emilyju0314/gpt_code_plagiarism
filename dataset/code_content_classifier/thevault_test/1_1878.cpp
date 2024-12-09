size_t trace::PerformanceBoundGenerator::computeMemoryDemand(const trace::TraceEvent &event, 
	CoalescingProtocol protocol) {
	
	size_t bytes = 0;
	
	// special handling of texture (assume coalesced reads)
	if (event.instruction->opcode == ir::PTXInstruction::Tex) {
		size_t elsize = 1;
		switch (event.instruction->d.type) {
			case ir::PTXOperand::s8:
			case ir::PTXOperand::u8:
			case ir::PTXOperand::b8:
				elsize = 1;
				break;
	
			case ir::PTXOperand::s16:
			case ir::PTXOperand::u16:
			case ir::PTXOperand::f16:
			case ir::PTXOperand::b16:
				elsize = 2;
				break;
	
			case ir::PTXOperand::s32:
			case ir::PTXOperand::u32:
			case ir::PTXOperand::b32:
			case ir::PTXOperand::f32:
				elsize = 4;
				break;
	
			case ir::PTXOperand::s64:
			case ir::PTXOperand::u64:
			case ir::PTXOperand::f64:
			case ir::PTXOperand::b64:
				elsize = 8;
				break;
				
			default:
				elsize = 0;
				break;
		}
		size_t vsize = (size_t)event.instruction->d.vec;
		
		bytes = (size_t)event.active.count() * elsize * vsize;
		return bytes;
	}
	
	switch (protocol) {
	case Protocol_sm_10:	// fall through
	case Protocol_sm_11:
	{
		size_t tid = 0;
		TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();
		size_t transactionSize = (event.memory_size == 16 ? 256 : (event.memory_size == 8 ? 128 : 64));

		std::vector< size_t > addresses;
		addresses.reserve(event.active.size());
		for (int n = 0; tid < event.active.size(); ++tid) {
			if (event.active[tid]) {
				addresses.push_back(event.memory_addresses[n]);
				++n;
			}
			else {
				addresses.push_back(0);
			}
		}
		
		// iterate over each half-warp
		std::map< size_t, size_t > transactions;
		for (tid = 0; tid < event.active.size(); tid += 16) {

			for (size_t t = 0; t < 16; t++) {
				size_t & address = addresses[t + tid];
				size_t base = (address & (~0x0f));
				if (address) {
					if (event.memory_size * t + base == address) {
						transactions[base] = transactionSize;
					}
					else {
						transactions[address] = transactionSize;
					}
				}
			}
			
			// add up the size of each transaction
			for (std::map<size_t, size_t>::const_iterator tr_it = transactions.begin();
				tr_it != transactions.end(); ++tr_it) {
				bytes += tr_it->second;
			}
			transactions.clear();
		}
		
	}
		break;
		
	case Protocol_sm_12:	// fall through
	case Protocol_sm_13:	// fall through
	case Protocol_sm_20:
	{
		size_t tid = 0;
		TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();

		std::vector< size_t > addresses;
		addresses.reserve(event.active.size());
		for (int n = 0; tid < event.active.size(); ++tid) {
			if (event.active[tid]) {
				addresses.push_back(event.memory_addresses[n]);
				++n;
			}
			else {
				addresses.push_back(0);
			}
		}
		
		// iterate over each half-warp
		std::map< size_t, size_t > transactions;
		for (tid = 0; tid < event.active.size(); tid += 16) {
			for (size_t t = 0; t < 16; t++) {
				size_t & address = addresses[t + tid];
				size_t base = (address & (~0x0f));
				if (address) {
					transactions[base] = (event.memory_size >= 2 ? 64 : 32);
				}
			}
			// add up the size of each transaction
			for (std::map<size_t, size_t>::const_iterator tr_it = transactions.begin();
				tr_it != transactions.end(); ++tr_it) {
				bytes += tr_it->second;
			}
			transactions.clear();
		}
	}
		break;
	
	// only count the actual number of distinct loads or stores	
	case Protocol_ideal:
	{
		std::map< size_t, size_t > transactions;
		for (TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();
			addr_it != event.memory_addresses.end(); ++addr_it) {
			transactions[*addr_it] = event.memory_size;
		}
		// add up the size of each transaction
		for (std::map<size_t, size_t>::const_iterator tr_it = transactions.begin();
			tr_it != transactions.end(); ++tr_it) {
			bytes += tr_it->second;
		}
	}
		break;
		
	default:
		break;
	}
	
	return bytes;
}