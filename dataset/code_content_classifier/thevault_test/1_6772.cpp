bool DCCPTCPlikeAgent::processOption(u_int8_t type, u_char* data, u_int8_t size, Packet *pkt){
	bool result = DCCPAgent::processOption(type, data, size, pkt);
	if (result){
		switch(type){
		case DCCP_OPT_ACK_VECTOR_N0:
		case DCCP_OPT_ACK_VECTOR_N1:
			//check if we received a new ack vector
			if (ackv_recv_ != NULL && ackv_recv_->getFirstSeqNum() >= high_ack_recv_){
				//check if we got all needed packets in the history
				if(hist_last_seq_ <= ackv_recv_->getLastSeqNum()){
					
					u_int8_t ene = 0;

					u_int32_t seqnum;
					dccp_packet_state state;
					
					struct dccp_tcplike_send_hist_entry *elm = STAILQ_FIRST(&send_hist_);
					//walk through the ack vector and compute the ECN Nonce Echo
					ackv_recv_->startPacketWalk();
					while(ackv_recv_->nextPacket(&seqnum, &state)){
						if (state == DCCP_PACKET_RECV){
							elm = findPacketInSendHistory(seqnum,elm);
							if (elm != NULL && elm->seq_num_ == seqnum){
								ene = ene ^ elm->ecn_;
							} else if (elm == NULL)
								break;
						}
					}
					//compare with the received echo
					if (ene != ackv_recv_->getENE()){
						fprintf(stdout,"%f, DCCP/TCPlike(%s)::processOption() - ECN check failed! \n", now(), name());
						sendReset(DCCP_RST_AGG_PEN,0,0,0);
						result = false;
					}
				} else
					debug("%f, DCCP/TCPlike(%s)::processOption() - Ack vector includes packets not in history. Skipping ecn check for now...\n", now(), name());
			} else if (ackv_recv_ != NULL)
				debug("%f, DCCP/TCPlike(%s)::processOption() - Old ack detected. Skipping ecn check\n", now(), name());
			break;
		case DCCP_OPT_QUIESCENCE:
			sender_quiescent_ = true;
			break;
		}
	}
	return result;
}