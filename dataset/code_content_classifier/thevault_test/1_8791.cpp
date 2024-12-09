int city_index(string name, string cities[]) {
	/** Convert name provided to uppercase for
	 * case-insensitive comparison
	 */
	uppercase(name);
	
	if(name == "TOLEDO") {
		return 0;
	}else if(name == "BANGOR") {
		return 1;
	}else if(name == "PERRIS") {
		return 2;
	}else if(name == "IONA") {
		return 3;
	}else if(name == "JUHU") {
		return 4;
	}else if(name == "MALIBU") {
		return 5;
	}else if(name == "SIERRA") {
		return 6;
	}else if(name == "TAOS") {
		return 7;
	}else if(name == "PACOIMA") {
		return 8;
	}else if(name == "NAPA") {
		return 9;
	}else{
		// Name provided is not one of the names of the candidates
		return -1;
	}
}