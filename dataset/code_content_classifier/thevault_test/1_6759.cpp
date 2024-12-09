void DCCPTCPlikeAgent::trimSendHistory(u_int32_t trim_to){
	if (trim_to > hist_last_seq_){
		struct dccp_tcplike_send_hist_entry *elm, *elm2;
		//find packet corresponding to trim_to
		elm = findPacketInSendHistory(trim_to, STAILQ_FIRST(&send_hist_));
		if (elm != NULL){
			//remove older packets
			elm2 = STAILQ_NEXT(elm, linfo_);	
			while (elm2 != NULL){
				STAILQ_REMOVE(&send_hist_,elm2,dccp_tcplike_send_hist_entry,linfo_);
				delete elm2;
				elm2 = STAILQ_NEXT(elm, linfo_);	
			}
		}
		hist_last_seq_ = trim_to;
	}
}