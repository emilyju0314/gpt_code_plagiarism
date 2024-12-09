void HardDrive::allocateMemory(int index, int n, char proc) {
	
	//For each memory unit
	for(int i = index; i < index+n; i++)
		if (!memory[i]) memory[i] = proc;
		else Err("allocateMemory called illegally");

    //Update memory used
    memoryUnused -= n;
}