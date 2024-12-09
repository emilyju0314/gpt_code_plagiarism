void totaler(){
	lint tcount = 0;	        //Number of testcases.
	lint pcount = 0;			//Testcases*100
	lint GLcountSn = 0;						// Number of Hassett chambers quotiented by Sn
	lint GLcount = 0;
	lint PScountSn = 0;
	lint PScount = 0;

	int finishedcount = 0;
	
	moodycamel::ConsumerToken ctok(countq);
	log("Totaler: Initiated\n");
	
	while(tcount < TOTALT) {
		std::tuple<int, int, int, int> retvals;
		countq.wait_dequeue(ctok, retvals);
		
		// Tally the counts
		tcount++; pcount += 100;
		GLcount += std::get<0>(retvals);
		GLcountSn += std::get<1>(retvals);
		PScount += std::get<2>(retvals);
		PScountSn += std::get<3>(retvals);

		// Mark progress
		static lint percent = 1;
		if ((pcount/TOTALT) >= percent) {
			std::stringstream stream;
			stream << "Totaler: " << percent << "% complete.\n";
			stream << "Current progress:\n";
			stream << "n = " << n << "\n";
			stream << "Number Tested : " << tcount << "\n";
			stream << "Number Goldilocks(/Sn): " << GLcountSn << "\n";
			stream << "Number Goldilocks: " << GLcount << "\n";
			stream << "Number SemiGold(/Sn): " << PScountSn << "\n";
			stream << "Number SemiGold: " << PScount << "\n";
			output(stream.str());

			percent++;
		}
	}

	// Output results
	cout << "Final Results!" << endl;
	cout << "n = " << n << endl;
	cout << "Number Tested : " << tcount << endl;
	cout << "Number Goldilocks(/Sn): " << GLcountSn << endl;
	cout << "Number Goldilocks: " << GLcount << endl;
	cout << "Number SemiGold (/Sn): " << PScountSn << endl;
	cout << "Number SemiGold: " << PScount << endl;
	
	std::stringstream stream;
	stream << "Final Results!\n";
	stream << "n = " << n << "\n";
	stream << "Number Tested : " << tcount << "\n";
	stream << "Number Goldilocks(/Sn): " << GLcountSn << "\n";
	stream << "Number Goldilocks: " << GLcount << "\n";
	stream << "Number SemiGold(/Sn): " << PScountSn << "\n";
	stream << "Number SemiGold: " << PScount << "\n";
	output(stream.str());
}