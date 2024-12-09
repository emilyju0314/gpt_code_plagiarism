void
OLSR::rm_nb2hop_tuple(OLSR_nb2hop_tuple* tuple) {
	debug("%f: Node %d removes 2-hop neighbor tuple: nb_addr = %d nb2hop_addr = %d\n",
		CURRENT_TIME,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->nb_main_addr()),
		OLSR::node_id(tuple->nb2hop_addr()));

	state_.erase_nb2hop_tuple(tuple);
}