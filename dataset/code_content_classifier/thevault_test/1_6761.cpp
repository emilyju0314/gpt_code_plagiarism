inline void DCCPTCPlikeAgent::clearSendRecvHistory(){
	struct dccp_tcplike_send_recv_hist_entry *elm, *elm2;

	/* Empty packet history */
	elm = STAILQ_FIRST(&send_recv_hist_);
	while (elm != NULL) {
		elm2 = STAILQ_NEXT(elm, linfo_);
		delete elm;
		elm = elm2;
	}
	
	STAILQ_INIT(&send_recv_hist_);
}