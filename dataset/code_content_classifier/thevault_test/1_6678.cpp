bool DCCPAckVector::addPacket(u_int32_t seqnum, dccp_ecn_codepoint ecn, bool addNonce){
	dccp_packet_state state = DCCP_PACKET_RECV;
	if (ecn == ECN_CE)
		state = DCCP_PACKET_ECN;

	bool result = addPacket(seqnum, state);
	if (result && addNonce && (ecn == ECN_ECT0 || ecn == ECN_ECT1))
		ene_ = ene_ ^ ecn;
	
	return result;
}