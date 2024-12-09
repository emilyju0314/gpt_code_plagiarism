void Receiver::printAverageTimes(){
	int Total = 0;
	double average1, average2;
	for (unsigned int x = 0; x < allTimesS1.size(); x++){
		Total += allTimesS1[x];
	}
	average1 = (double)Total/(allTimesS1.size());
	Total = 0;
	for (unsigned int y = 0; y < allTimesS1.size(); y++){
		Total += allTimesS2[y];
	}
	average2 = (double)Total/(allTimesS2.size());
	cout << "The average time for packets from S1 is " << average1 << " sims, and the average time for packets from S2 is " << average2 << " sims." << endl;
}