void
OLSR::forward_default(Packet* p, OLSR_msg& msg, OLSR_dup_tuple* dup_tuple, nsaddr_t local_iface) {
	double now		= CURRENT_TIME;
	struct hdr_ip* ih	= HDR_IP(p);
	
	// If the sender interface address is not in the symmetric
	// 1-hop neighborhood the message must not be forwarded
	OLSR_link_tuple* link_tuple = state_.find_sym_link_tuple(ih->saddr(), now);
	if (link_tuple == NULL)
		return;

	// If the message has already been considered for forwarding,
	// it must not be retransmitted again
	if (dup_tuple != NULL && dup_tuple->retransmitted()) {
		debug("%f: Node %d does not forward a message received"
			" from %d because it is duplicated\n",
			CURRENT_TIME,
			OLSR::node_id(ra_addr()),
			OLSR::node_id(dup_tuple->addr()));
		return;
	}
	
	// If the sender interface address is an interface address
	// of a MPR selector of this node and ttl is greater than 1,
	// the message must be retransmitted
	bool retransmitted = false;
	if (msg.ttl() > 1) {
		OLSR_mprsel_tuple* mprsel_tuple =
			state_.find_mprsel_tuple(get_main_addr(ih->saddr()));
		if (mprsel_tuple != NULL) {
			OLSR_msg& new_msg = msg;
			new_msg.ttl()--;
			new_msg.hop_count()++;
			// We have to introduce a random delay to avoid
			// synchronization with neighbors.
			enque_msg(new_msg, JITTER);
			retransmitted = true;
		}
	}
	
	// Update duplicate tuple...
	if (dup_tuple != NULL) {
		dup_tuple->time()		= now + OLSR_DUP_HOLD_TIME;
		dup_tuple->retransmitted()	= retransmitted;
		dup_tuple->iface_list().push_back(local_iface);
	}
	// ...or create a new one
	else {
		OLSR_dup_tuple* new_dup = new OLSR_dup_tuple;
		new_dup->addr()			= msg.orig_addr();
		new_dup->seq_num()		= msg.msg_seq_num();
		new_dup->time()			= now + OLSR_DUP_HOLD_TIME;
		new_dup->retransmitted()	= retransmitted;
		new_dup->iface_list().push_back(local_iface);
		add_dup_tuple(new_dup);
		// Schedules dup tuple deletion
		OLSR_DupTupleTimer* dup_timer =
			new OLSR_DupTupleTimer(this, new_dup);
		dup_timer->resched(DELAY(new_dup->time()));
	}
}