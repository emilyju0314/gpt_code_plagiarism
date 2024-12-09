void BinarySearchNode::printNode(){
	if(word=="")
		return;
	cout << left << setw(25) << setfill(' ') << word << "|" << right << setw(5) << setfill(' ') << count << "|" << left;
	printLines();
	cout << endl;
}