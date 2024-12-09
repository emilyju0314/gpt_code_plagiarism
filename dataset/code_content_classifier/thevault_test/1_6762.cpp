bool DCCPTCPlikeAgent::insertInSendRecvHistory(dccp_tcplike_send_recv_hist_entry *packet){
	struct dccp_tcplike_send_recv_hist_entry *elm, *elm2;
	int num_later = 0;
	
	if (STAILQ_EMPTY(&send_recv_hist_)){  //history is empty
		STAILQ_INSERT_HEAD(&send_recv_hist_, packet, linfo_);
	} else {  //history contains at least one entry
		elm = STAILQ_FIRST(&send_recv_hist_);
		if (packet->seq_num_ > elm->seq_num_)  //insert first in history
			STAILQ_INSERT_HEAD(&send_recv_hist_, packet, linfo_);
		else if (packet->seq_num_ == elm->seq_num_) //duplicate
			return false;
		else {  //packet should be inserted somewhere after the head
			num_later = 1;

			//walk through the history to find the correct place
			elm2 = STAILQ_NEXT(elm,linfo_);
			while(elm2 != NULL){
				if (packet->seq_num_ > elm2->seq_num_){
					STAILQ_INSERT_AFTER(&send_recv_hist_, elm, packet, linfo_);
					break;
				} else if (packet->seq_num_ == elm2->seq_num_) {
					return false;  //duplicate
				}
				
				elm = elm2;
				elm2 = STAILQ_NEXT(elm,linfo_);
				
				num_later++;
				
				if (num_later == num_dup_acks_){  //packet is "lost"
					return false;
				}
			}
			
			if(elm2 == NULL && num_later < num_dup_acks_){
				STAILQ_INSERT_TAIL(&send_recv_hist_, packet, linfo_);
			}
			
		}
	}
	return true;
}