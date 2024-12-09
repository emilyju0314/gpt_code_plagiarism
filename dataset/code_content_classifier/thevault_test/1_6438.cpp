void
OLSR_printer::print_olsr_tc(FILE* out, OLSR_tc& tc) {
	fprintf(out, "\tansn = %d\n\treserved = %d\n",
		tc.ansn(),
		tc.reserved());
	printf("\tansn = %d\n\treserved = %d\n",
		tc.ansn(),
		tc.reserved());
	for (int i = 0; i < tc.count; i++){
		fprintf(out, "\taddr = %d\n", tc.nb_main_addr(i));
		printf("\taddr = %d\n", tc.nb_main_addr(i));}
}