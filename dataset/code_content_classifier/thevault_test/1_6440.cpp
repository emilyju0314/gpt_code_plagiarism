void
OLSR_printer::print_linkset(Trace* out, linkset_t& linkset) {
	sprintf(out->pt_->buffer(), "P\tlocal\tnb\tsym\t\tasym\t\tlost\t\ttime");
	printf("P\tlocal\tnb\tsym\t\tasym\t\tlost\t\ttime\n");
	out->pt_->dump();
	for (linkset_t::iterator it = linkset.begin(); it != linkset.end(); it++) {
		OLSR_link_tuple* tuple = *it;
		sprintf(out->pt_->buffer(), "P\t%d\t%d\t%f\t%f\t%f\t%f",
			OLSR::node_id(tuple->local_iface_addr()),
			OLSR::node_id(tuple->nb_iface_addr()),
			tuple->sym_time(),
			tuple->asym_time(),
			tuple->lost_time(),
			tuple->time());
		printf("P\t%d\t%d\t%f\t%f\t%f\t%f\n",
			OLSR::node_id(tuple->local_iface_addr()),
			OLSR::node_id(tuple->nb_iface_addr()),
			tuple->sym_time(),
			tuple->asym_time(),
			tuple->lost_time(),
			tuple->time());
		out->pt_->dump();
	}
}