void trace::MemoryTraceGenerator::event(const TraceEvent & event) {
	using namespace ir;

	_header.dynamic_instructions++;
	_header.dynamic_operations += (PTXU64)event.active.count();
	
	if (event.instruction->opcode == PTXInstruction::Ld 
		|| event.instruction->opcode == PTXInstruction::St) {
		
		if( !headerOnly )
		{
			_event = Event();
			_event.PC = event.PC;
			_event.opcode = event.instruction->opcode;
			_event.addressSpace = event.instruction->addressSpace;
			_event.ctaX = event.blockId.x;
			_event.ctaY = event.blockId.y;
			_event.ctaZ = event.blockId.z;
		}
		
		// form the accesses vector of the event
		PTXU64 bytes = 0;
		PTXU32 threadID = 0;
		PTXU64 starting_address = -1;
		PTXU32 halfwarpSize = _header.thread_count / 2;
		
		if(!event.memory_addresses.empty())
		{
			++_header.halfwarps;
		}
		
		for (TraceEvent::U64Vector::const_iterator it = event.memory_addresses.begin();
			it != event.memory_addresses.end(); ++it, ++threadID) {
		
			if( !headerOnly )
			{
				for (; threadID < _header.thread_count 
					&& !event.active[threadID]; threadID++) { }
			
				Access access;
				access.address = *it;
				access.threadID = threadID;
				access.size = event.memory_size;

				_event.accesses.push_back(access);
			}
			
			_header.address(event.instruction->addressSpace, *it);
			bytes += event.memory_size;
			
			if( threadID > halfwarpSize )
			{
				++_header.global_segments;
				++_header.halfwarps;
				starting_address = *it + event.memory_size;
			}
			else if( starting_address != *it )
			{
				++_header.global_segments;
				starting_address = *it + event.memory_size;
			}
		}
		
		// memory operation
		_header.access(event.instruction->addressSpace, bytes);

		if( !headerOnly )
		{
			*_archive << _event;
		}
	}
	else if (event.instruction->opcode == PTXInstruction::Tex) {
		if( !headerOnly )
		{
			_event = Event();
			_event.PC = event.PC;
			_event.opcode = event.instruction->opcode;
			_event.addressSpace = PTXInstruction::Texture;
			_event.ctaX = event.blockId.x;
			_event.ctaY = event.blockId.y;
			_event.ctaZ = event.blockId.z;
		}
		
		PTXU64 bytes = 0;
		PTXU32 threadID = 0;
		PTXU64 starting_address = -1;
		PTXU32 halfwarpSize = _header.thread_count / 2;
		TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();
		for (; addr_it != event.memory_addresses.end(); ++threadID, ++addr_it) {
			if( !headerOnly )
			{
				for (; threadID < _header.thread_count 
					&& !event.active[threadID]; ++threadID) { }
			
				for (int j = 0; j < 4; j++) {
					Access access;
					access.address = *addr_it;
					access.size = event.memory_size;
					access.threadID = threadID;
				
					_event.accesses.push_back(access);
				}
			}
			bytes += event.memory_size;
			_header.address(PTXInstruction::Texture, *addr_it);
			
			if( threadID > halfwarpSize )
			{
				++_header.global_segments;
				++_header.halfwarps;
				starting_address = *addr_it + event.memory_size;
			}
			else if( starting_address != *addr_it )
			{
				++_header.global_segments;
				starting_address = *addr_it + event.memory_size;
			}
			
		}
		
		_header.access(PTXInstruction::Texture, bytes);
		
		if( !headerOnly )
		{
			*_archive << _event;
		}
	}
}