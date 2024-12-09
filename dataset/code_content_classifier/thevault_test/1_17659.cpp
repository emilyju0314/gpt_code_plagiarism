Packet::Packet(int apacketID, int aTimeStamp, int size, vector<int> sourceRoute){
	packetID = apacketID;
	timeStamp = aTimeStamp;
	packetSize = size;
	SR = sourceRoute;
	sender = SR[0];
	SR.erase(SR.begin());
	next = NULL;
}