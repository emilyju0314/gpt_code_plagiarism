void
OLSR_printer::print_topologyset(Trace* out, topologyset_t& topologyset) {
	sprintf(out->pt_->buffer(), "P\tdest\tlast\tseq\ttime");
	printf("P\tdest\tlast\tseq\ttime\n");
	out->pt_->dump();
	for (topologyset_t::iterator it = topologyset.begin(); it != topologyset.end(); it++) {
		OLSR_topology_tuple* topology_tuple = *it;
		sprintf(out->pt_->buffer(), "P\t%d\t%d\t%d\t%f",
			OLSR::node_id(topology_tuple->dest_addr()),
			OLSR::node_id(topology_tuple->last_addr()),
			topology_tuple->seq(),
			topology_tuple->time());
		printf("P\t%d\t%d\t%d\t%f\n",
			OLSR::node_id(topology_tuple->dest_addr()),
			OLSR::node_id(topology_tuple->last_addr()),
			topology_tuple->seq(),
			topology_tuple->time());
		out->pt_->dump();
	}
}