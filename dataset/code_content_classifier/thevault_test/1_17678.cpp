int Sender::addPackets(int simTime){
	if (numPackets > counter){
		Packet *aPacket = new Packet(((getID() * 1000) + counter), (simTime + packetSize), packetSize, SR);
		counter++;
		if (DEBUG){
			cout << "Packet " << aPacket->getPacketID() << " has been created in sender " << getID() << " at time " << simTime << " sims." << endl << endl; 
			aPacket->printSR();
		}
		sendToTQ(aPacket);
		setCTT(packetSize);
		return 1;
	}
	return 0;
}