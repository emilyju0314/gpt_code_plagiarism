int candidate_index(string name, string candidate[]) {
	/** Convert name provided to uppercase for
	 * case-insensitive comparison
	 */
	uppercase(name);
	
	if(name == "BUSH") {
		return 0;
	}else if(name == "KERRY") {
		return 1;
	}else if(name == "NADER") {
		return 2;
	}else if(name == "ARMSTRONG") {
		return 3;
	}else if(name == "BUCHANAN") {
		return 4;
	}else{
		// Name provided is not one of the names of the candidates
		return -1;
	}
}