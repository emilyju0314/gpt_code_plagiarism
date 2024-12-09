void Sender::addFromFile(string fileName, int simTime){
	static long positionAlongFile;
	static int numberAdded;
	static int numberAddedS1;
	static int numberAddedS2;
	if (numberAddedS1 == AMOUNTFROMEACH && getName() == "S1"){
		return;
	}
	if (numberAdded != (AMOUNTFROMEACH*2)){
		FILE *thisFile;
		int aPacketID;
		thisFile = fopen((fileName + ".txt").c_str(), "r");
		if(thisFile != NULL){
			fseek(thisFile, positionAlongFile, SEEK_SET);
			fscanf(thisFile, "%d", &aPacketID);
			positionAlongFile = ftell(thisFile);
			fclose(thisFile);
			if (DEBUG){
				printf("Adding packet %d from ", aPacketID);
				cout << getName() << endl;
			}
			Link aNode = new Node(aPacketID, simTime);
			sendToTQ(aNode);
			if (getName() == "S1"){
				numberAddedS1++;
			}
			else {
				numberAddedS2++;
			}
			numberAdded++;
		}
		else{
			printf("Error opening file\n");
		}
	}
}