OLSR_rtable::~OLSR_rtable() {
	// Iterates over the routing table deleting each OLSR_rt_entry*.
	for (rtable_t::iterator it = rt_.begin(); it != rt_.end(); it++)
		delete (*it).second;
}