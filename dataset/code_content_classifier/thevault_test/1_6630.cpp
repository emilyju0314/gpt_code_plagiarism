void
OLSR::process_mid(OLSR_msg& msg, nsaddr_t sender_iface) {
	assert(msg.msg_type() == OLSR_MID_MSG);
	double now	= CURRENT_TIME;
	OLSR_mid& mid	= msg.mid();
	
	// 1. If the sender interface of this message is not in the symmetric
	// 1-hop neighborhood of this node, the message MUST be discarded.
	OLSR_link_tuple* link_tuple = state_.find_sym_link_tuple(sender_iface, now);
	if (link_tuple == NULL)
		return;
	
	// 2. For each interface address listed in the MID message
	for (int i = 0; i < mid.count; i++) {
		bool updated = false;
		for (ifaceassocset_t::iterator it = ifaceassocset().begin();
			it != ifaceassocset().end();
			it++) {
			OLSR_iface_assoc_tuple* tuple = *it;
			if (tuple->iface_addr() == mid.iface_addr(i)
				&& tuple->main_addr() == msg.orig_addr()) {
				tuple->time()	= now + OLSR::emf_to_seconds(msg.vtime());
				updated		= true;
			}			
		}
		if (!updated) {
			OLSR_iface_assoc_tuple* tuple	= new OLSR_iface_assoc_tuple;
			tuple->iface_addr()		= msg.mid().iface_addr(i);
			tuple->main_addr()		= msg.orig_addr();
			tuple->time()			= now + OLSR::emf_to_seconds(msg.vtime());
			add_ifaceassoc_tuple(tuple);
			// Schedules iface association tuple deletion
			OLSR_IfaceAssocTupleTimer* ifaceassoc_timer =
				new OLSR_IfaceAssocTupleTimer(this, tuple);
			ifaceassoc_timer->resched(DELAY(tuple->time()));
		}
	}
}