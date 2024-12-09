void trace::WarpSynchronousGenerator::finish() {

	report("WarpSynchronousGenerator::finish()");

	// always update database and emit results as JSON
	outputSynchronousStatistics();

	if (TraceConfiguration::Singleton.warpSynchronous.emitHotPaths) {
		// emit DOT files
		for (std::vector<int>::const_iterator ws_it = warpSizes.begin();
			ws_it != warpSizes.end(); ++ws_it) {
			int warpSize = *ws_it;
			report("  outputting hot paths - ws: " << warpSize);
			outputHotPaths(warpSize);
		}
	}
}