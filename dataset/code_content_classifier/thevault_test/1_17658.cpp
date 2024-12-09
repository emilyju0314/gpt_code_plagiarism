void FCFS::addEvent(Link thisNode){
	thisNode->setPropogationTime(propogationTime);
	if (DEBUG){
		cout << name << " has received packet " << thisNode->getPacketID() << endl;
	}
	transmissionQuene.bringToBack(thisNode);
}