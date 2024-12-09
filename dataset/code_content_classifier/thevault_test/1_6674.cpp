void DCCPAckVector::clearAckHistory(){
	struct dccp_ackv_hist_entry *elm, *elm2;

	/* Empty packet history */
	elm = STAILQ_FIRST(&ack_hist_);
	while (elm != NULL) {
		elm2 = STAILQ_NEXT(elm, linfo_);
		delete elm;
		elm = elm2;
	}
	
	STAILQ_INIT(&ack_hist_);
}