OLSR_rt_entry*
OLSR_rtable::lookup(nsaddr_t dest) {
	// Get the iterator at "dest" position
	rtable_t::iterator it = rt_.find(dest);
	// If there is no route to "dest", return NULL
	if (it == rt_.end())
		return NULL;
	
	// Returns the rt entry (second element of the pair)
	return (*it).second;
}