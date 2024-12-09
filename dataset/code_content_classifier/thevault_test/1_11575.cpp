int HardDrive::findNextFreeChunk(int index) const {
    
    //Make sure this was called legally
    Assert(0<=index&&index<size(), "Index out of bounds");
    
    //Set true if a block of used memory has been found
    int i, foundUsed = false;
    
    //Repeat for each index in memory
    for(i=index+1; i < size(); i++) {
        
        //If a used block of memory has yet to be found
        if (!foundUsed) {
            if (memory[i]) foundUsed = true;
        }
        
        //If a new chunk was found, return it's index
        else if (!memory[i]) return i;
    }
    
    //If no memory is free
    return -1;
}