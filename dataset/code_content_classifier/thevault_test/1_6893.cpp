void DCCPAgent::recv_packetRecv(Packet *pkt, int dataSize) {
	hdr_dccp *dccph = hdr_dccp::access(pkt);

	if (dccph->type_ != DCCP_DATA && dccph->type_ != DCCP_DATAACK
	    && dccph->type_ != DCCP_ACK){
		fprintf(stderr,"%f, DCCP(%s)::recv_packetRecv() - Got a packet of type %s!\n", now(), name(), packetTypeAsStr(dccph->type_));
		fflush(stdout);
		abort();
	}

	//ack ackording to ack ratio
	if(dccph->type_ == DCCP_DATA || dccph->type_ == DCCP_DATAACK){
		ar_unacked_++;
		if (ar_unacked_ >= ack_ratio_local_){
			send_ack_ = true;
			ack_num_ = seq_num_recv_;
			ar_unacked_= 0;
			output_ = true;
			output_flag_ = true;
		}
	}
}