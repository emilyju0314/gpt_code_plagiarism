OLSR_rt_entry*
OLSR_rtable::add_entry(nsaddr_t dest, nsaddr_t next, nsaddr_t iface, u_int32_t dist) {
	// Creates a new rt entry with specified values
	OLSR_rt_entry* entry = new OLSR_rt_entry();
	entry->dest_addr()	= dest;
	entry->next_addr()	= next;
	entry->iface_addr()	= iface;
	entry->dist()		= dist;
	
	// Inserts the new entry
	rtable_t::iterator it = rt_.find(dest);
	if (it != rt_.end())
		delete (*it).second;
	rt_[dest] = entry;
	
	// Returns the new rt entry
	return entry;
}