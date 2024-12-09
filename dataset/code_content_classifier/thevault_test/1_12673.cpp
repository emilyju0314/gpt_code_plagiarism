void printUsage() {
	cout << "JSGF Matching" << endl << \
		"Usage:" << endl << \
		"\tjsgfmatch -f GRAMMAR_FILE (-r | -t)" << endl << endl << \
		"\t-f\tSpecifies the path to the grammar file to parse." << endl << \
		"\t-r\tSpecifies to print out the public rule that the input matches, if any." << endl << \
		"\t-t\tSpecifies to print out the tag(s) that the input matches, if any." << endl << endl <<\
		"\t-p\tSpecifies to print out the grammar once it is parsed." << endl <<\
		"When printing matching tags, if there are multiple tags, they will be printed out separated by commas in order of appearance. The tags will not include the { } characters." << endl << endl << \
		"Author: Tyler Sengia <ExpandingDev> (tylersengia@gmail.com)" << endl;
}