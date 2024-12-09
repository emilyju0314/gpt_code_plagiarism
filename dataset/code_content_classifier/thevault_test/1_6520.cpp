void
OLSR_rtable::rm_entry(nsaddr_t dest) {
	// Remove the pair whose key is dest
	rt_.erase(dest);
}