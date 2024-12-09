void DCCPTCPlikeAgent::printSendRecvHistory(){
	struct dccp_tcplike_send_recv_hist_entry *elm = STAILQ_FIRST(&send_recv_hist_);
	if (elm == NULL)
		fprintf(stdout, "Packet history is empty (send recv)\n");
	else {
		fprintf(stdout, "Packet history (send recv):\n");
		while(elm != NULL){
			fprintf(stdout,"Packet: seq %d, type %s, ndp %d\n", elm->seq_num_, packetTypeAsStr(elm->type_), elm->ndp_);
			elm = STAILQ_NEXT(elm, linfo_);
		}
	}	
}