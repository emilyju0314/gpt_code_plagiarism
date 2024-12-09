int Packet::getNextFCFS(){
	int nextItem = SR[0];
	SR.erase(SR.begin());
	return nextItem;
}