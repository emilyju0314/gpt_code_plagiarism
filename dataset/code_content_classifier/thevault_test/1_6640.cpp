void
OLSR::populate_nb2hopset(OLSR_msg& msg) {
	double now		= CURRENT_TIME;
	OLSR_hello& hello	= msg.hello();
	
	for (linkset_t::iterator it_lt = linkset().begin(); it_lt != linkset().end(); it_lt++) {
		OLSR_link_tuple* link_tuple = *it_lt;
		if (get_main_addr(link_tuple->nb_iface_addr()) == msg.orig_addr()) {
			if (link_tuple->sym_time() >= now) {
				assert(hello.count >= 0 && hello.count <= OLSR_MAX_HELLOS);
				for (int i = 0; i < hello.count; i++) {
					OLSR_hello_msg& hello_msg = hello.hello_msg(i);
					int nt = hello_msg.link_code() >> 2;
					assert(hello_msg.count >= 0 &&
						hello_msg.count <= OLSR_MAX_ADDRS);
					
					for (int j = 0; j < hello_msg.count; j++) {
						nsaddr_t nb2hop_addr = hello_msg.nb_iface_addr(j);
						if (nt == OLSR_SYM_NEIGH || nt == OLSR_MPR_NEIGH) {
							// if the main address of the 2-hop
							// neighbor address = main address of
							// the receiving node: silently
							// discard the 2-hop neighbor address
							if (nb2hop_addr != ra_addr()) {
								// Otherwise, a 2-hop tuple is created
								OLSR_nb2hop_tuple* nb2hop_tuple =
									state_.find_nb2hop_tuple(msg.orig_addr(), nb2hop_addr);
								if (nb2hop_tuple == NULL) {
									nb2hop_tuple =
										new OLSR_nb2hop_tuple;
									nb2hop_tuple->nb_main_addr() =
										msg.orig_addr();
									nb2hop_tuple->nb2hop_addr() =
										nb2hop_addr;
									add_nb2hop_tuple(nb2hop_tuple);
									nb2hop_tuple->time() =
										now + OLSR::emf_to_seconds(msg.vtime());
									// Schedules nb2hop tuple
									// deletion
									OLSR_Nb2hopTupleTimer* nb2hop_timer =
										new OLSR_Nb2hopTupleTimer(this, nb2hop_tuple);
									nb2hop_timer->resched(DELAY(nb2hop_tuple->time()));
								}
								else {
									nb2hop_tuple->time() =
										now + OLSR::emf_to_seconds(msg.vtime());
								}
								
							}
						}
						else if (nt == OLSR_NOT_NEIGH) {
							// For each 2-hop node listed in the HELLO
							// message with Neighbor Type equal to
							// NOT_NEIGH all 2-hop tuples where:
							// N_neighbor_main_addr == Originator
							// Address AND N_2hop_addr  == main address
							// of the 2-hop neighbor are deleted.
							state_.erase_nb2hop_tuples(msg.orig_addr(),
								nb2hop_addr);
						}
					}
				}
			}
		}
	}
}