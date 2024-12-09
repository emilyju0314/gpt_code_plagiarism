void
OLSR::link_sensing(OLSR_msg& msg, nsaddr_t receiver_iface, nsaddr_t sender_iface) {
	OLSR_hello& hello	= msg.hello();
	double now		= CURRENT_TIME;
	bool updated		= false;
	bool created		= false;
	
	OLSR_link_tuple* link_tuple = state_.find_link_tuple(sender_iface);
	if (link_tuple == NULL) {
		// We have to create a new tuple
		link_tuple = new OLSR_link_tuple;
		link_tuple->nb_iface_addr()	= sender_iface;
		link_tuple->local_iface_addr()	= receiver_iface;
		link_tuple->sym_time()		= now - 1;
		link_tuple->lost_time()		= 0.0;
		link_tuple->time()		= now + OLSR::emf_to_seconds(msg.vtime());
		add_link_tuple(link_tuple, hello.willingness());
		created = true;
	}
	else
		updated = true;
	
 	link_tuple->asym_time() = now + OLSR::emf_to_seconds(msg.vtime());
	assert(hello.count >= 0 && hello.count <= OLSR_MAX_HELLOS);
	for (int i = 0; i < hello.count; i++) {
		OLSR_hello_msg& hello_msg = hello.hello_msg(i);
		int lt = hello_msg.link_code() & 0x03;
		int nt = hello_msg.link_code() >> 2;
		
		// We must not process invalid advertised links
		if ((lt == OLSR_SYM_LINK && nt == OLSR_NOT_NEIGH) ||
			(nt != OLSR_SYM_NEIGH && nt != OLSR_MPR_NEIGH
			&& nt != OLSR_NOT_NEIGH))
			continue;
		
		assert(hello_msg.count >= 0 && hello_msg.count <= OLSR_MAX_ADDRS);
		for (int j = 0; j < hello_msg.count; j++) {
			if (hello_msg.nb_iface_addr(j) == receiver_iface) {
				if (lt == OLSR_LOST_LINK) {
					link_tuple->sym_time() = now - 1;
					updated = true;
				}
				else if (lt == OLSR_SYM_LINK || lt == OLSR_ASYM_LINK) {
					link_tuple->sym_time()	=
						now + OLSR::emf_to_seconds(msg.vtime());
					link_tuple->time()	=
						link_tuple->sym_time() + OLSR_NEIGHB_HOLD_TIME;
					link_tuple->lost_time()	= 0.0;
					updated = true;
				}
				break;
			}
		}
		
	}
	link_tuple->time() = MAX(link_tuple->time(), link_tuple->asym_time());
	
	if (updated)
		updated_link_tuple(link_tuple);
	
	// Schedules link tuple deletion
	if (created && link_tuple != NULL) {
		OLSR_LinkTupleTimer* link_timer =
			new OLSR_LinkTupleTimer(this, link_tuple);
		link_timer->resched(DELAY(MIN(link_tuple->time(), link_tuple->sym_time())));
	}
}