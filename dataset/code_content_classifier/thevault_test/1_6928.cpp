void edgeQueue::enque(Packet* pkt) {

	// Mark the packet with the specified priority:
	//printf("before ,mark\n");
	policy.mark(pkt);
	//	printf("after ,mark\n");
	dsREDQueue::enque(pkt);
}