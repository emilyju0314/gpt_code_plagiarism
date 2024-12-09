void
OLSR::send_pkt() {
	int num_msgs = msgs_.size();
	if (num_msgs == 0)
		return;
	
	// Calculates the number of needed packets
	int num_pkts = (num_msgs%OLSR_MAX_MSGS == 0) ? num_msgs/OLSR_MAX_MSGS :
		(num_msgs/OLSR_MAX_MSGS + 1);
	
	for (int i = 0; i < num_pkts; i++) {
		Packet* p		= allocpkt();
		struct hdr_cmn* ch	= HDR_CMN(p);
		struct hdr_ip* ih	= HDR_IP(p);
		OLSR_pkt* op		= PKT_OLSR(p);
		
		op->pkt_len()		= OLSR_PKT_HDR_SIZE;
		op->pkt_seq_num()	= pkt_seq();
	
		int j = 0;
		for (std::vector<OLSR_msg>::iterator it = msgs_.begin(); it != msgs_.end(); it++) {
			if (j == OLSR_MAX_MSGS)
				break;
			
			op->pkt_body_[j++]	= *it;
			op->count		= j;
			op->pkt_len()		+= (*it).size();
			
			it = msgs_.erase(it);
			it--;
		}
	
		ch->ptype()		= PT_OLSR;
		ch->direction()		= hdr_cmn::DOWN;
		ch->size()		= IP_HDR_LEN + UDP_HDR_LEN + op->pkt_len();
		ch->error()		= 0;
		ch->next_hop()		= IP_BROADCAST;
		ch->addr_type()		= NS_AF_INET;
		if (use_mac()) {
			ch->xmit_failure_	= olsr_mac_failed_callback;
			ch->xmit_failure_data_	= (void*)this;
		}

		ih->saddr()	= ra_addr();
		ih->daddr()	= IP_BROADCAST;
		ih->sport()	= RT_PORT;
		ih->dport()	= RT_PORT;
		ih->ttl()	= IP_DEF_TTL;
		
		Scheduler::instance().schedule(target_, p, 0.0);
	}
}