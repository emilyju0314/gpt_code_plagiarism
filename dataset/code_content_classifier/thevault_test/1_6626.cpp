void
OLSR::recv_olsr(Packet* p) {
	struct hdr_ip* ih	= HDR_IP(p);
	OLSR_pkt* op		= PKT_OLSR(p);
	
	// All routing messages are sent from and to port RT_PORT,
	// so we check it.
	assert(ih->sport() == RT_PORT);
	assert(ih->dport() == RT_PORT);
	
	// If the packet contains no messages must be silently discarded.
	// There could exist a message with an empty body, so the size of
	// the packet would be pkt-hdr-size + msg-hdr-size.
	if (op->pkt_len() < OLSR_PKT_HDR_SIZE + OLSR_MSG_HDR_SIZE) {
		Packet::free(p);
		return;
	}
	
	assert(op->count >= 0 && op->count <= OLSR_MAX_MSGS);
	for (int i = 0; i < op->count; i++) {
		OLSR_msg& msg = op->msg(i);
		
		// If ttl is less than or equal to zero, or
		// the receiver is the same as the originator,
		// the message must be silently dropped
		if (msg.ttl() <= 0 || msg.orig_addr() == ra_addr())
			continue;
		
		// If the message has been processed it must not be
		// processed again
		bool do_forwarding = true;
		OLSR_dup_tuple* duplicated = state_.find_dup_tuple(msg.orig_addr(), msg.msg_seq_num());
		if (duplicated == NULL) {
			// Process the message according to its type
			if (msg.msg_type() == OLSR_HELLO_MSG)
				process_hello(msg, ra_addr(), ih->saddr());
			else if (msg.msg_type() == OLSR_TC_MSG)
				process_tc(msg, ih->saddr());
			else if (msg.msg_type() == OLSR_MID_MSG)
				process_mid(msg, ih->saddr());
			else {
				debug("%f: Node %d can not process OLSR packet because does not "
					"implement OLSR type (%x)\n",
					CURRENT_TIME,
					OLSR::node_id(ra_addr()),
					msg.msg_type());
			}
		}
		else {
			// If the message has been considered for forwarding, it should
			// not be retransmitted again
			for (addr_list_t::iterator it = duplicated->iface_list().begin();
				it != duplicated->iface_list().end();
				it++) {
				if (*it == ra_addr()) {
					do_forwarding = false;
					break;
				}
			}
		}
			
		if (do_forwarding) {
			// HELLO messages are never forwarded.
			// TC and MID messages are forwarded using the default algorithm.
			// Remaining messages are also forwarded using the default algorithm.
			if (msg.msg_type() != OLSR_HELLO_MSG)
				forward_default(p, msg, duplicated, ra_addr());
		}

	}
	
	// After processing all OLSR messages, we must recompute routing table
	rtable_computation();
	
	// Release resources
	Packet::free(p);
}