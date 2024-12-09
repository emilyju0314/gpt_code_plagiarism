string generate_repitition(int rep, char c) {
	string ret = ""; //result

	//creates a repetition of the specified character c
	for (int i = 0; i < rep; ++i) ret += c;

	//returns the repetition
	return ret;
}