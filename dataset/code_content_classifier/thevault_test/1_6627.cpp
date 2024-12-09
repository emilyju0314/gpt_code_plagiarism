void
OLSR::rtable_computation() {
	// 1. All the entries from the routing table are removed.
	rtable_.clear();
	
	// 2. The new routing entries are added starting with the
	// symmetric neighbors (h=1) as the destination nodes.
	for (nbset_t::iterator it = nbset().begin(); it != nbset().end(); it++) {
		OLSR_nb_tuple* nb_tuple = *it;
		if (nb_tuple->status() == OLSR_STATUS_SYM) {
			bool nb_main_addr = false;
			OLSR_link_tuple* lt = NULL;
			for (linkset_t::iterator it2 = linkset().begin(); it2 != linkset().end(); it2++) {
				OLSR_link_tuple* link_tuple = *it2;
				if (get_main_addr(link_tuple->nb_iface_addr()) == nb_tuple->nb_main_addr() && link_tuple->time() >= CURRENT_TIME) {
					lt = link_tuple;
					rtable_.add_entry(link_tuple->nb_iface_addr(),
							link_tuple->nb_iface_addr(),
							link_tuple->local_iface_addr(),
							1);
					if (link_tuple->nb_iface_addr() == nb_tuple->nb_main_addr())
						nb_main_addr = true;
				}
			}
			if (!nb_main_addr && lt != NULL) {
				rtable_.add_entry(nb_tuple->nb_main_addr(),
						lt->nb_iface_addr(),
						lt->local_iface_addr(),
						1);
			}
		}
	}
	
	// N2 is the set of 2-hop neighbors reachable from this node, excluding:
	// (i)   the nodes only reachable by members of N with willingness WILL_NEVER
	// (ii)  the node performing the computation
	// (iii) all the symmetric neighbors: the nodes for which there exists a symmetric
	//       link to this node on some interface.
	for (nb2hopset_t::iterator it = nb2hopset().begin(); it != nb2hopset().end(); it++) {
		OLSR_nb2hop_tuple* nb2hop_tuple = *it;
		bool ok = true;
		OLSR_nb_tuple* nb_tuple = state_.find_sym_nb_tuple(nb2hop_tuple->nb_main_addr());
		if (nb_tuple == NULL)
			ok = false;
		else {
			nb_tuple = state_.find_nb_tuple(nb2hop_tuple->nb_main_addr(), OLSR_WILL_NEVER);
			if (nb_tuple != NULL)
				ok = false;
			else {
				nb_tuple = state_.find_sym_nb_tuple(nb2hop_tuple->nb2hop_addr());
				if (nb_tuple != NULL)
					ok = false;
			}
		}

		// 3. For each node in N2 create a new entry in the routing table
		if (ok) {
			OLSR_rt_entry* entry = rtable_.lookup(nb2hop_tuple->nb_main_addr());
			assert(entry != NULL);
			rtable_.add_entry(nb2hop_tuple->nb2hop_addr(),
					entry->next_addr(),
					entry->iface_addr(),
					2);
		}
	}
	
	for (u_int32_t h = 2; ; h++) {
		bool added = false;
		
		// 4.1. For each topology entry in the topology table, if its
		// T_dest_addr does not correspond to R_dest_addr of any
		// route entry in the routing table AND its T_last_addr
		// corresponds to R_dest_addr of a route entry whose R_dist
		// is equal to h, then a new route entry MUST be recorded in
		// the routing table (if it does not already exist)
		for (topologyset_t::iterator it = topologyset().begin();
			it != topologyset().end();
			it++) {
			OLSR_topology_tuple* topology_tuple = *it;
			OLSR_rt_entry* entry1 = rtable_.lookup(topology_tuple->dest_addr());
			OLSR_rt_entry* entry2 = rtable_.lookup(topology_tuple->last_addr());
			if (entry1 == NULL && entry2 != NULL && entry2->dist() == h) {
				rtable_.add_entry(topology_tuple->dest_addr(),
						entry2->next_addr(),
						entry2->iface_addr(),
						h+1);
				added = true;
			}
		}
		
		// 5. For each entry in the multiple interface association base
		// where there exists a routing entry such that:
		//	R_dest_addr  == I_main_addr  (of the multiple interface association entry)
		// AND there is no routing entry such that:
		//	R_dest_addr  == I_iface_addr
		// then a route entry is created in the routing table
		for (ifaceassocset_t::iterator it = ifaceassocset().begin();
			it != ifaceassocset().end();
			it++) {
			OLSR_iface_assoc_tuple* tuple = *it;
			OLSR_rt_entry* entry1 = rtable_.lookup(tuple->main_addr());
			OLSR_rt_entry* entry2 = rtable_.lookup(tuple->iface_addr());
			if (entry1 != NULL && entry2 == NULL) {
				rtable_.add_entry(tuple->iface_addr(),
						entry1->next_addr(),
						entry1->iface_addr(),
						entry1->dist());
				added = true;
			}
		}

		if (!added)
			break;
	}
}