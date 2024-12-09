void
OLSR_printer::print_mprset(Trace* out, mprset_t& mprset) {
	sprintf(out->pt_->buffer(), "P\tnb");
	printf("P\tnb\n");
	out->pt_->dump();
	for (mprset_t::iterator it = mprset.begin(); it != mprset.end(); it++) {
		sprintf(out->pt_->buffer(), "P\t%d", OLSR::node_id(*it));
		printf("P\t%d\n", OLSR::node_id(*it));
		out->pt_->dump();
	}
}