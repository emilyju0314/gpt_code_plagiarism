void
OLSR_printer::print_olsr_mid(FILE* out, OLSR_mid& mid) {
	for (int i = 0; i < mid.count; i++){
		fprintf(out, "\tiface = %d\n", mid.iface_addr(i));
		printf("\tiface = %d\n", mid.iface_addr(i));}
}