void
OLSR_printer::print_mprselset(Trace* out, mprselset_t& mprselset) {
	sprintf(out->pt_->buffer(), "P\tnb\ttime");
	printf("P\tnb\ttime\n");
	out->pt_->dump();
	for (mprselset_t::iterator it = mprselset.begin(); it != mprselset.end(); it++) {
		OLSR_mprsel_tuple* mprsel_tuple = *it;
		sprintf(out->pt_->buffer(), "P\t%d\t%f",
			OLSR::node_id(mprsel_tuple->main_addr()),
			mprsel_tuple->time());
		printf("P\t%d\t%f\n",
			OLSR::node_id(mprsel_tuple->main_addr()),
			mprsel_tuple->time());
		out->pt_->dump();
	}
}