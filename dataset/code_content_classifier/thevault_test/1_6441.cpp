void
OLSR_printer::print_nbset(Trace* out, nbset_t& nbset) {
	sprintf(out->pt_->buffer(), "P\tnb\tstatus\twillingness");
	printf("P\tnb\tstatus\twillingness\n");
	out->pt_->dump();
	for (nbset_t::iterator it = nbset.begin(); it != nbset.end(); it++) {
		OLSR_nb_tuple* tuple = *it;
		sprintf(out->pt_->buffer(), "P\t%d\t%d\t%d",
			OLSR::node_id(tuple->nb_main_addr()),
			tuple->status(),
			tuple->willingness());
		printf("P\t%d\t%d\t%d\n",
			OLSR::node_id(tuple->nb_main_addr()),
			tuple->status(),
			tuple->willingness());
		out->pt_->dump();
	}
}