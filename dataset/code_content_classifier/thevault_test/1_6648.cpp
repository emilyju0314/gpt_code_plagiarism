void
OLSR::updated_link_tuple(OLSR_link_tuple* tuple) {
	double now = CURRENT_TIME;
	
	// Each time a link tuple changes, the associated neighbor tuple must be recomputed
	OLSR_nb_tuple* nb_tuple =
		state_.find_nb_tuple(get_main_addr(tuple->nb_iface_addr()));
	if (nb_tuple != NULL) {
		if (use_mac() && tuple->lost_time() >= now)
			nb_tuple->status() = OLSR_STATUS_NOT_SYM;
		else if (tuple->sym_time() >= now)
			nb_tuple->status() = OLSR_STATUS_SYM;
		else
			nb_tuple->status() = OLSR_STATUS_NOT_SYM;
	
	debug("%f: Node %d has updated link tuple: nb_addr = %d status = %s\n",
		now,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->nb_iface_addr()),
		((nb_tuple->status() == OLSR_STATUS_SYM) ? "sym" : "not_sym"));
	}
}