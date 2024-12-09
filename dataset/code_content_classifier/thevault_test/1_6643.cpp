void
OLSR::nb_loss(OLSR_link_tuple* tuple) {
	debug("%f: Node %d detects neighbor %d loss\n",
		CURRENT_TIME,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->nb_iface_addr()));
	
	updated_link_tuple(tuple);
	state_.erase_nb2hop_tuples(get_main_addr(tuple->nb_iface_addr()));
	state_.erase_mprsel_tuples(get_main_addr(tuple->nb_iface_addr()));
	
	mpr_computation();
 	rtable_computation();
}