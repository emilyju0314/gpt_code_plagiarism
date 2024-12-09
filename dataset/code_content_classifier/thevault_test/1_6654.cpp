void
OLSR::rm_mprsel_tuple(OLSR_mprsel_tuple* tuple) {
	debug("%f: Node %d removes MPR selector tuple: nb_addr = %d\n",
		CURRENT_TIME,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->main_addr()));

	state_.erase_mprsel_tuple(tuple);
	ansn_ = (ansn_ + 1)%(OLSR_MAX_SEQ_NUM + 1);
}