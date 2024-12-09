void DCCPTCPlikeAgent::printSendHistory(){
	struct dccp_tcplike_send_hist_entry *elm = STAILQ_FIRST(&send_hist_);
	if (elm == NULL)
		fprintf(stdout, "Packet history is empty (send)\n");
	else {
		fprintf(stdout, "Packet history (send):\n");
		while(elm != NULL){
			fprintf(stdout,"Packet: seq %d, t_sent %f, ecn %d\n", elm->seq_num_, elm->t_sent_, elm->ecn_);
			elm = STAILQ_NEXT(elm, linfo_);
		}
	}
}