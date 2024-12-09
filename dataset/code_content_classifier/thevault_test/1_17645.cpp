void BinarySearchNode::printLines(){
	for (unsigned int x = 0; x < listOfLines.size(); x++){
		if(x == (listOfLines.size()-1)){
			cout<< right << setw(4) << setfill(' ') << listOfLines[x];
			return;
		}
		cout << right << setw(4) << setfill(' ')<< listOfLines[x] << ",";
	}
}