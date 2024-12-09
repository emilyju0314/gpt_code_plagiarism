void DCCPAckVector::ackRecv(u_int32_t acknum, DCCPAckVector *ackv){
	struct dccp_ackv_hist_entry *elm = NULL, *next_elm = NULL;
	dccp_packet_state state;
	u_int8_t ene_sub = 0;
	
	elm = STAILQ_FIRST(&ack_hist_);
	while (elm != NULL){
		if (ackv == NULL) {
			if (acknum == elm->seq_sent_)
				break;
		} else if (ackv->getState(elm->seq_sent_, &state) && (state == DCCP_PACKET_RECV || state == DCCP_PACKET_ECN)){
			break;
		}
		elm = STAILQ_NEXT(elm, linfo_);
	}

	if (elm != NULL){
		ene_sub = elm->ene_;
		ene_ = ene_ ^ (elm->ene_);
		removePackets(elm->ack_num_);
		do{
		       next_elm = STAILQ_NEXT(elm, linfo_);
		       STAILQ_REMOVE(&ack_hist_,elm,dccp_ackv_hist_entry,linfo_);
		       delete elm;
		       elm = next_elm;
		} while (elm != NULL);

		//subtract ene from later acks
		elm = STAILQ_FIRST(&ack_hist_);
		while (elm != NULL) {
			elm->ene_ = (elm->ene_) ^ ene_sub;
			elm = STAILQ_NEXT(elm, linfo_);
		}
	}
	
}