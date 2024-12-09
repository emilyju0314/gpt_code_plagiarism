void
OLSR::process_tc(OLSR_msg& msg, nsaddr_t sender_iface) {
	assert(msg.msg_type() == OLSR_TC_MSG);
	double now	= CURRENT_TIME;
	OLSR_tc& tc	= msg.tc();
	
	// 1. If the sender interface of this message is not in the symmetric
	// 1-hop neighborhood of this node, the message MUST be discarded.
	OLSR_link_tuple* link_tuple = state_.find_sym_link_tuple(sender_iface, now);
	if (link_tuple == NULL)
		return;
	
	// 2. If there exist some tuple in the topology set where:
	// 	T_last_addr == originator address AND
	// 	T_seq       >  ANSN,
	// then further processing of this TC message MUST NOT be
	// performed.
	OLSR_topology_tuple* topology_tuple =
		state_.find_newer_topology_tuple(msg.orig_addr(), tc.ansn());
	if (topology_tuple != NULL)
		return;
	
	// 3. All tuples in the topology set where:
	//	T_last_addr == originator address AND
	//	T_seq       <  ANSN
	// MUST be removed from the topology set.
	state_.erase_older_topology_tuples(msg.orig_addr(), tc.ansn());

	// 4. For each of the advertised neighbor main address received in
	// the TC message:
	for (int i = 0; i < tc.count; i++) {
		assert(i >= 0 && i < OLSR_MAX_ADDRS);
		nsaddr_t addr = tc.nb_main_addr(i);
		// 4.1. If there exist some tuple in the topology set where:
		// 	T_dest_addr == advertised neighbor main address, AND
		// 	T_last_addr == originator address,
		// then the holding time of that tuple MUST be set to:
		// 	T_time      =  current time + validity time.
		OLSR_topology_tuple* topology_tuple =
			state_.find_topology_tuple(addr, msg.orig_addr());
		if (topology_tuple != NULL)
			topology_tuple->time() = now + OLSR::emf_to_seconds(msg.vtime());
		// 4.2. Otherwise, a new tuple MUST be recorded in the topology
		// set where:
		//	T_dest_addr = advertised neighbor main address,
		//	T_last_addr = originator address,
		//	T_seq       = ANSN,
		//	T_time      = current time + validity time.
		else {
			OLSR_topology_tuple* topology_tuple = new OLSR_topology_tuple;
			topology_tuple->dest_addr()	= addr;
			topology_tuple->last_addr()	= msg.orig_addr();
			topology_tuple->seq()		= tc.ansn();
			topology_tuple->time()		= now + OLSR::emf_to_seconds(msg.vtime());
			add_topology_tuple(topology_tuple);
			// Schedules topology tuple deletion
			OLSR_TopologyTupleTimer* topology_timer =
				new OLSR_TopologyTupleTimer(this, topology_tuple);
			topology_timer->resched(DELAY(topology_tuple->time()));
		}
	}
}