void write_output(string outputfilename, string cities[],
	string candidate_names[],
	int number_of_votes_per_city_per_candidate[NUMBER_OF_CANDIDATES][NUMBER_OF_CITIES]) {
	
	// Create output file stream
	ofstream outputfile;
	/**
	 * Convert outputfilename to string in C so that the file I/O function
	 * in the C++ library can be utilised
	 */
	outputfile.open(outputfilename.c_str());
	// Assertion to check if the output file was opened properly
	if(outputfile == NULL) {
		cout << "Output file, with the filename " << outputfilename
		<< ", does not exist!" << endl;
	}
	
	// Determine the total votes for all candidates across all cities...
	int total_tally[NUMBER_OF_CANDIDATES];
	for(int m=0; m<NUMBER_OF_CANDIDATES; m++) {
		total_tally[m]=0;
	}
	
	// Determine the index of the winning candidate...
	// Index of the winning candidate's name in the name list
	int winner_index=0;
	
	outputfile << "Report of Totals for Each Candidate and City:" << endl;
	// Left align the data...
	outputfile.setf(ios::left);
	outputfile.width(14);
	outputfile << "   ";
	// Print the list of cities
	for(int i=0; i<NUMBER_OF_CITIES; i++) {
		outputfile.width(14);
		outputfile << cities[i];
	}
	outputfile << endl;
	
	// Print the list of candidates and their vote tallies for each city
	for(int j=0; j<NUMBER_OF_CANDIDATES; j++) {
		outputfile.width(14);
		outputfile << candidate_names[j];
		for(int k=0; k<NUMBER_OF_CITIES; k++) {
			outputfile.width(14);
			outputfile << number_of_votes_per_city_per_candidate[j][k];
			total_tally[j] = total_tally[j]
				+ number_of_votes_per_city_per_candidate[j][k];
		}
		outputfile << endl;
		if(total_tally[j]>total_tally[winner_index]) {
			winner_index=j;
		}
	}
	
	outputfile << endl;
	outputfile << "Total Votes for Candidate across all Cities:" << endl;
	for(int n=0; n<NUMBER_OF_CANDIDATES; n++) {
		outputfile.width(14);
		outputfile << candidate_names[n];
		outputfile.width(14);
		outputfile << total_tally[n] << endl;
	}
	
	outputfile << endl;
	outputfile << "Winner of the election is: "
		<< candidate_names[winner_index] << endl;
	
	// Close the output filestream
	outputfile.close();
}