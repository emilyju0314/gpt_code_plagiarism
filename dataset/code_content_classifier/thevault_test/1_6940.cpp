void RapAgent::SendAck(int seqNum)
{
	type_ = PT_RAP_ACK;
	Packet* pkt = allocpkt();	// Create a new packet
	hdr_rap* hdr = hdr_rap::access(pkt);   // Access header

	hdr->seqno() = seqNum;
	hdr->flags() = RH_ACK;

	hdr->lastRecv = lastRecv_;
	hdr->lastMiss = lastMiss_;
	hdr->prevRecv = prevRecv_;

	hdr_cmn *ch = hdr_cmn::access(pkt);
	ch->size() = rap_base_hdr_size_;

	send(pkt, 0);
	Debug(debugEnable_, logfile_, 
	      "- ack sent %u [%u %u %u]\n", 
	      seqNum, lastRecv_, lastMiss_, prevRecv_);
}