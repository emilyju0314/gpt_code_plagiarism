void DCCPAckVector::print(){
	if (isEmpty()) {
		fprintf(stdout, "DCCPAckVector :: Ack vector is empty (max_size_ %d)\n",max_size_);
	} else {
		fprintf(stdout, "DCCPAckVector :: size_ %d, max_size_ %d, head_ %d, tail_ %d, seq_head_ %d, seq_tail_ %d, ene_ %d\n", size_, max_size_,head_,tail_,seq_head_,seq_tail_, ene_);
		startIntervalWalk();
		u_char interval;
		u_int32_t seq_start;
		u_int32_t seq_end;
		dccp_packet_state state;

		while(nextInterval(&interval, &seq_start, &seq_end, &state)){
			fprintf(stdout, "interval 0x%X (%d): state %s, runlen %d, (seq %d - %d)\n",interval, interval, packetStateAsStr(state), seq_start-seq_end,seq_start,seq_end);
		}
	}
	printHistory();
}