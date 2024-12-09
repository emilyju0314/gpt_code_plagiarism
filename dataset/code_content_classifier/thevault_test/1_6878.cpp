bool DCCPAgent::checkPacket(Packet* pkt){
	bool new_pkt;
	bool result = true;
	hdr_cmn* cmnh = hdr_cmn::access(pkt);
	hdr_dccp* dccph = hdr_dccp::access(pkt);
	hdr_dccpack* dccpah = hdr_dccpack::access(pkt);

	if (cmnh->error()){  //e.g. "checksum failed"
		debug("%f, DCCP(%s)::checkPacket() - Packet is corrupt (%d)\n",
			      now(), name(), dccph->seq_num_);
		return false;
	}
	
	bool ack_recv = (dccph->type_ != DCCP_DATA) && (dccph->type_ != DCCP_REQUEST);
	if (ack_recv && packet_sent_ && dccpah->ack_num_ >= seq_num_){
		//invalid ack_num_
		debug("%f, DCCP(%s)::checkPacket() - Ack num not valid (%d)\n",
			      now(), name(), dccpah->ack_num_);
		return false;
	} else if (ack_recv && !packet_sent_){
		//if no packet has been sent, allow only resets with acknum 0
		if (!(dccph->type_ == DCCP_RESET && dccpah->ack_num_ == 0)){
			debug("%f, DCCP(%s)::checkPacket() - Ack num not valid (No packet sent!) (%d)\n",
			      now(), name(), dccpah->ack_num_);
			return false;
		}
	}
		
	new_pkt = (dccph->seq_num_ > seq_num_recv_);

	if (dccph->type_ == DCCP_RESET) //reset is always valid 
		result = true;
	else
		switch (state_){
		case DCCP_STATE_CLOSED:
			result = false;
			break;
		case DCCP_STATE_LISTEN:
			result = (dccph->type_ == DCCP_REQUEST);
		break;
		case DCCP_STATE_RESPOND:
			result = (new_pkt && dccph->type_ == DCCP_REQUEST ||
				  dccph->type_ == DCCP_CLOSE ||
				  new_pkt && dccph->type_ == DCCP_ACK ||
				  new_pkt && dccph->type_ == DCCP_DATAACK);
			break;
		case DCCP_STATE_OPEN:
			result = (dccph->type_ == DCCP_CLOSE ||
				  dccph->type_ == DCCP_CLOSEREQ && !server_ ||
				  dccph->type_ == DCCP_ACK ||
				  dccph->type_ == DCCP_DATA ||
				  dccph->type_ == DCCP_DATAACK);
			break;
		case DCCP_STATE_REQUEST:
			result = (dccph->type_ == DCCP_RESPONSE
				  && dccpah->ack_num_ == seq_num_-1 ||
				  dccph->type_ == DCCP_CLOSE);
			break;
		case DCCP_STATE_CLOSEREQ:
			result = (dccph->type_ == DCCP_CLOSE ||
				  dccph->type_ == DCCP_ACK ||
				  dccph->type_ == DCCP_DATA ||
				  dccph->type_ == DCCP_DATAACK);
		break;
		case DCCP_STATE_CLOSING:
			result = (dccph->type_ == DCCP_CLOSEREQ ||
				  dccph->type_ == DCCP_ACK ||
				  dccph->type_ == DCCP_DATA ||
				  dccph->type_ == DCCP_DATAACK);
		break;

		default:
			fprintf(stderr, "%f, DCCP(%s):checkPacket() - Illegal state (%d)!\n",
			now(), name(),state_);
			fflush(stdout);
			abort();
		}
	
	if (result){
		//set highest seqnum and acknum recv so far
		if (seq_num_recv_ < dccph->seq_num_)
			seq_num_recv_ = dccph->seq_num_;
		if (ack_recv && ack_num_recv_ < dccpah->ack_num_)
			ack_num_recv_ = dccpah->ack_num_;
	}
	return result;
}