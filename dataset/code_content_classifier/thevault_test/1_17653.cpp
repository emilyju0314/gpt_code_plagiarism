void BinarySearchTree::printTree(){
	//after text file is done being parsed, set up header for the table of words
	cout << left << setw(25) << setfill(' ') << "Word" << "|" << left << setw(5) << setfill(' ') << "Count" << "|" << "Lines" << endl;
	printTree(startPointer);
	//Once it is printed, we print out the total unique words. 
	cout << left << setw(25) << setfill(' ') << "Total Unique Words" << "|";
	cout << (numOfWords(startPointer)-1) << endl;
}