Link Packet::decrementItems(){
	propogationTime -= 1;
	if (DEBUG){
		cout << packetID << " is on the Propogation Queue and has a time of "<< propogationTime << endl;
	}
	if (next != NULL){
		next = next->decrementItems();
	}
	return this;
}