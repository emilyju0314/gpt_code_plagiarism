void
OLSR_printer::print_ip_hdr(FILE* out, struct hdr_ip* ih) {
	fprintf(out,
		"  IP HEADER\n\tsrc_addr = %d\n\tsrc_port = %d\n\tdest_addr = %d\n\tdest_port = %d\n\tttl = %d\n\n",
		ih->saddr(),
		ih->sport(),
		ih->daddr(),
		ih->dport(),
		ih->ttl());
	printf("IP HEADER\n\tsrc_addr = %d\n\tsrc_port = %d\n\tdest_addr = %d\n\tdest_port = %d\n\tttl = %d\n\n",ih->saddr(),ih->sport(),ih->daddr(),ih->dport(),ih->ttl());
}