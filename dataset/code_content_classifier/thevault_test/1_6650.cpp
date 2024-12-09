void
OLSR::rm_nb_tuple(OLSR_nb_tuple* tuple) {
	debug("%f: Node %d removes neighbor tuple: nb_addr = %d status = %s\n",
		CURRENT_TIME,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->nb_main_addr()),
		((tuple->status() == OLSR_STATUS_SYM) ? "sym" : "not_sym"));
	
	state_.erase_nb_tuple(tuple);
}