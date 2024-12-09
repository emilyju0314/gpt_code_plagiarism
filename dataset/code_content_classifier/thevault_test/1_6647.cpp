void
OLSR::rm_link_tuple(OLSR_link_tuple* tuple) {
	nsaddr_t nb_addr	= get_main_addr(tuple->nb_iface_addr());
	double now		= CURRENT_TIME;
	
	debug("%f: Node %d removes link tuple: nb_addr = %d\n",
		now,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->nb_iface_addr()));
	// Prints this here cause we are not actually calling rm_nb_tuple() (efficiency stuff)
	debug("%f: Node %d removes neighbor tuple: nb_addr = %d\n",
		now,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(nb_addr));

	state_.erase_link_tuple(tuple);
	
	OLSR_nb_tuple* nb_tuple = state_.find_nb_tuple(nb_addr);
	state_.erase_nb_tuple(nb_tuple);
	delete nb_tuple;
}