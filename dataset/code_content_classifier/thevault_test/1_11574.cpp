std::pair<int, int> HardDrive::findNextFit(int index, int n) const {

	//Check for incorrect usage;
    Assert(canFit(n), "Out of memory");
    Assert(index>=0&&index<size(), "illegal index passed");

	//Record starting index
	int k, i = index;

	//Repeat for each index in memory
	do {
		
		//Check to see if n units of memory can fit
        for(k = 0; k < n && (i+k) < size(); k++) if (memory[i+k]) break;
        
        //If it can fit
        if (k == n) {
            
            //Find extra space
            for( k = 0; (k+i+n) < size(); k++ ) if (memory[k+i+n]) break;
            
            //Return the result
            return std::make_pair(i, k);
        }
				
		//Increment index, circularly in memory
		if (++i >= size()) i = 0;
	} while(i != index);
	
    //If it can't fit, return -1s
    return std::make_pair(-1,-1);
}