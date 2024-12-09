void DCCPAckVector::printPackets(bool asc){
	if (isEmpty()) {
		fprintf(stdout, "DCCPAckVector :: Ack vector is empty (max_size_ %d)\n",max_size_);
	} else {
		fprintf(stdout, "DCCPAckVector :: size_ %d, max_size_ %d, head_ %d, tail_ %d, seq_head_ %d, seq_tail_ %d, ene_ %d\n", size_, max_size_,head_,tail_,seq_head_,seq_tail_, ene_);
		u_int32_t seq_num;
		dccp_packet_state state;

		if (asc){
			startReversePacketWalk();
			while(prevPacket(&seq_num,&state)){
				fprintf(stdout, "Packet : seq %d state %s\n",seq_num, packetStateAsStr(state));
			}
		} else {
			startPacketWalk();
			while(nextPacket(&seq_num,&state)){
				fprintf(stdout, "Packet : seq %d state %s\n",seq_num, packetStateAsStr(state));
			}
		}
	}
}