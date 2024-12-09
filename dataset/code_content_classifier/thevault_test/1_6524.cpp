void
OLSR_rtable::print(Trace* out) {
	sprintf(out->pt_->buffer(), "P\tdest\tnext\tiface\tdist");
	out->pt_->dump();
	for (rtable_t::iterator it = rt_.begin(); it != rt_.end(); it++) {
		OLSR_rt_entry* entry = (*it).second;
		sprintf(out->pt_->buffer(), "P\t%d\t%d\t%d\t%d",
			OLSR::node_id(entry->dest_addr()),
			OLSR::node_id(entry->next_addr()),
			OLSR::node_id(entry->iface_addr()),
			entry->dist());
		printf("\tdest\tnext\tiface\tdist\n");
		printf("\t%d\t%d\t%d\t%d\n",OLSR::node_id(entry->dest_addr()),OLSR::node_id(entry->next_addr()),OLSR::node_id(entry->iface_addr()),entry->dist());
		out->pt_->dump();
	}
}