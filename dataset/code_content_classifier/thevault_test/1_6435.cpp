void
OLSR_printer::print_olsr_pkt(FILE* out, OLSR_pkt* pkt) {
	fprintf(out,
		"  OLSR PACKET\n\tlength = %d\n\tseq_num = %d\n\t------------\n",
		pkt->pkt_len(),
		pkt->pkt_seq_num());
	printf("OLSR PACKET\n\tlength = %d\n\tseq_num = %d\n\t------------\n",pkt->pkt_len(),pkt->pkt_seq_num());
	
	for (int i = 0; i < pkt->count; i++) {
		print_olsr_msg(out, pkt->msg(i));
		fprintf(out, "\t------------\n");
		printf("\t------------\n");
	}
	fprintf(out, "\n");
	printf("\n");
}