int Tool_extract::isInList(int number, vector<int>& listofnum) {
	int i;
	for (i=0; i<(int)listofnum.size(); i++) {
		if (listofnum[i] == number) {
			return i+1;
		}
	}
	return 0;

}