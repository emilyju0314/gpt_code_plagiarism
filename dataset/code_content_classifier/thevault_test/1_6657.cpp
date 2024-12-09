void
OLSR::add_ifaceassoc_tuple(OLSR_iface_assoc_tuple* tuple) {
	debug("%f: Node %d adds iface association tuple: main_addr = %d iface_addr = %d\n",
		CURRENT_TIME,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->main_addr()),
		OLSR::node_id(tuple->iface_addr()));

	state_.insert_ifaceassoc_tuple(tuple);
}