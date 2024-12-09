void
OLSR::add_link_tuple(OLSR_link_tuple* tuple, u_int8_t  willingness) {
	double now = CURRENT_TIME;

	debug("%f: Node %d adds link tuple: nb_addr = %d\n",
		now,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(tuple->nb_iface_addr()));

	state_.insert_link_tuple(tuple);
	// Creates associated neighbor tuple
	OLSR_nb_tuple* nb_tuple		= new OLSR_nb_tuple;
	nb_tuple->nb_main_addr()	= get_main_addr(tuple->nb_iface_addr());
	nb_tuple->willingness()		= willingness;
	if (tuple->sym_time() >= now)
		nb_tuple->status() = OLSR_STATUS_SYM;
	else
		nb_tuple->status() = OLSR_STATUS_NOT_SYM;
	add_nb_tuple(nb_tuple);
}