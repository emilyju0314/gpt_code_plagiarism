void
OLSR::rm_dup_tuple(OLSR_dup_tuple* tuple) {
	debug("%f: Node %d removes dup tuple: addr = %d seq_num = %d\n",
		CURRENT_TIME,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->addr()),
		tuple->seq_num());//remove comment
	
	state_.erase_dup_tuple(tuple);
}