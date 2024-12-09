void trace::WarpSynchronousGenerator::event( const trace::TraceEvent& event ) {
	for (std::map< int, SynchronousInstructionCounter >::iterator counter_it = warpCounters.begin();
		counter_it != warpCounters.end(); ++counter_it) {
		counter_it->second.event(counter_it->first, event);
	}
}