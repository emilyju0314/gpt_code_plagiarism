void
OLSR_printer::print_nb2hopset(Trace* out, nb2hopset_t& nb2hopset) {
	sprintf(out->pt_->buffer(), "P\tnb\tnb2hop\ttime");
	printf("P\tnb\tnb2hop\ttime\n");
	out->pt_->dump();
	for (nb2hopset_t::iterator it = nb2hopset.begin(); it != nb2hopset.end(); it++) {
		OLSR_nb2hop_tuple* tuple = *it;
		sprintf(out->pt_->buffer(), "P\t%d\t%d\t%f",
			OLSR::node_id(tuple->nb_main_addr()),
			OLSR::node_id(tuple->nb2hop_addr()),
			tuple->time());
		printf("P\t%d\t%d\t%f\n",
			OLSR::node_id(tuple->nb_main_addr()),
			OLSR::node_id(tuple->nb2hop_addr()),
			tuple->time());
		out->pt_->dump();
	}
}