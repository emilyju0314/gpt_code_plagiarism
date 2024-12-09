void DCCPAckVector::addToAckHistory(u_int32_t seqnum){
	struct dccp_ackv_hist_entry *elm = STAILQ_FIRST(&ack_hist_);
	if(elm != NULL && elm->seq_sent_ >= seqnum){
		fprintf(stderr, "DCCPAckVector::addToAckHistory - Sequence number to send is old! (seqnum %d < seq_sent_ %d)\n",seqnum, elm->seq_sent_);
		fflush(stdout);
		abort();
	} else if (elm != NULL && elm->ack_num_ > seq_head_) {
		fprintf(stderr, "DCCPAckVector::addToAckHistory - Last Ack number %d is larger than seq_head_ %d\n", elm->ack_num_, seq_head_);
		fflush(stdout);
		abort();
	} else {
		/*if (elm != NULL && elm->ack_num_ == seq_head_) {
			fprintf(stderr, "DCCPAckVector::addToAckHistory - Last Ack number %d is equal to seq_head_ %d\n", elm->ack_num_, seq_head_);
			fflush(stdout);
			abort();
			}*/
		struct dccp_ackv_hist_entry *new_entry = new struct dccp_ackv_hist_entry;
		new_entry->seq_sent_ = seqnum;
		new_entry->ack_num_ = seq_head_;
		new_entry->ene_ = ene_;
		STAILQ_INSERT_HEAD(&ack_hist_, new_entry, linfo_);
	}
}