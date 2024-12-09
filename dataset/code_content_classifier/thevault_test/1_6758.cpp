inline struct dccp_tcplike_send_hist_entry* DCCPTCPlikeAgent::findPacketInSendHistory(u_int32_t seq_num, dccp_tcplike_send_hist_entry* start_elm){
	struct dccp_tcplike_send_hist_entry *elm = start_elm;
	while (elm != NULL && elm->seq_num_ > seq_num)
		elm = STAILQ_NEXT(elm, linfo_);
	return elm;
}