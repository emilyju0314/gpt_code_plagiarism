void
OLSR::add_topology_tuple(OLSR_topology_tuple* tuple) {
	debug("%f: Node %d adds topology tuple: dest_addr = %d last_addr = %d seq = %d\n",
		CURRENT_TIME,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->dest_addr()),
		OLSR::node_id(tuple->last_addr()),
		tuple->seq());

	state_.insert_topology_tuple(tuple);
}