OLSR_rt_entry*
OLSR_rtable::find_send_entry(OLSR_rt_entry* entry) {
	OLSR_rt_entry* e = entry;
	while (e != NULL && e->dest_addr() != e->next_addr())
		e = lookup(e->next_addr());
	return e;
}