void CodeGenerator::updateLocation( CodeLocation const & to ) {
		// skip if linemarks shouldn't appear or if codelocation is unset
		if ( !options.lineMarks || to.isUnset() ) return;

		if ( currentLocation.followedBy( to, 0 ) ) {
			return;
		} else if ( currentLocation.followedBy( to, 1 ) ) {
			output << "\n" << indent;
			currentLocation.first_line += 1;
		} else if ( currentLocation.followedBy( to, 2 ) ) {
			output << "\n\n" << indent;
			currentLocation.first_line += 2;
		} else {
			output << "\n# " << to.first_line << " \"" << to.filename
				   << "\"\n" << indent;
			currentLocation = to;
		}
		output << std::flush;
	}