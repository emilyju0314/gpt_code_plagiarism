void
OLSR::populate_mprselset(OLSR_msg& msg) {
	double now		= CURRENT_TIME;
	OLSR_hello& hello	= msg.hello();
	
	assert(hello.count >= 0 && hello.count <= OLSR_MAX_HELLOS);
	for (int i = 0; i < hello.count; i++) {
		OLSR_hello_msg& hello_msg = hello.hello_msg(i);
		int nt = hello_msg.link_code() >> 2;
		if (nt == OLSR_MPR_NEIGH) {
			assert(hello_msg.count >= 0 && hello_msg.count <= OLSR_MAX_ADDRS);
			for (int j = 0; j < hello_msg.count; j++) {
				if (hello_msg.nb_iface_addr(j) == ra_addr()) {
					// We must create a new entry into the mpr selector set
					OLSR_mprsel_tuple* mprsel_tuple =
						state_.find_mprsel_tuple(msg.orig_addr());
					if (mprsel_tuple == NULL) {
						mprsel_tuple = new OLSR_mprsel_tuple;
						mprsel_tuple->main_addr() = msg.orig_addr();
						mprsel_tuple->time() =
							now + OLSR::emf_to_seconds(msg.vtime());
						add_mprsel_tuple(mprsel_tuple);
						// Schedules mpr selector tuple deletion
						OLSR_MprSelTupleTimer* mprsel_timer =
							new OLSR_MprSelTupleTimer(this, mprsel_tuple);
						mprsel_timer->resched(DELAY(mprsel_tuple->time()));
					}
					else
						mprsel_tuple->time() =
							now + OLSR::emf_to_seconds(msg.vtime());
				}
			}
		}
	}
}