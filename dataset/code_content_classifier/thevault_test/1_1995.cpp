void trace::InstructionTraceGenerator::finish() {
	//
	// stream to file
	//
	_entry.updateDatabase( database );

	std::ofstream hfile( _entry.header.c_str() );
	boost::archive::text_oarchive harchive( hfile );

	if(!hfile.is_open()) {
	
		throw hydrazine::Exception(
			"Failed to open InstructionTraceGenerator header file " 
			+ _entry.header );
	}
	
	// visit every instruction counter and divide activity by thread count
	if (threadCount) {
		for (FunctionalUnitCountMap::iterator fu_it = instructionCounter.begin(); 
			fu_it != instructionCounter.end(); ++fu_it) {
	
			for (OpcodeCountMap::iterator oc_it = fu_it->second.begin(); oc_it != fu_it->second.end();
				++oc_it) {
			
	//			if (threadCount != 0 && oc_it->second.dynamic_count != 0) {
	//				oc_it->second.activity /= (double)threadCount * (double)oc_it->second.dynamic_count;
	//			}
	//			else {
	//				oc_it->second.activity = 0;
	//			}
				oc_it->second.dynamic_count *= threadCount;
			}
		}
	}
	
	harchive << _header;
	harchive << instructionCounter;
	
	hfile.close();
}