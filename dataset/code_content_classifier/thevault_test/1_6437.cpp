void
OLSR_printer::print_olsr_hello(FILE* out, OLSR_hello& hello) {	
	fprintf(out, "\thtime = %.2f\n\twillingness = %d\n",
		OLSR::emf_to_seconds(hello.htime()),
		hello.willingness());
	printf("\thtime = %.2f\n\twillingness = %d\n",
		OLSR::emf_to_seconds(hello.htime()),
		hello.willingness());
	
	for (int i = 0; i < hello.count; i++) {
		char *nt, *lt;
		OLSR_hello_msg msg = hello.hello_msg(i);
		
		u_int8_t nb_type = msg.link_code() >> 2;
		u_int8_t link_type = msg.link_code() & 0x03;
		if (nb_type == OLSR_NOT_NEIGH)
			nt = "NOT_NEIGH";
		else if (nb_type == OLSR_SYM_NEIGH)
			nt = "SYM_NEIGH";
		else if (nb_type == OLSR_MPR_NEIGH)
			nt = "MPR_NEIGH";
		else
			nt = "UNKNOWN (likely a bug!)";
		
		if (link_type == OLSR_UNSPEC_LINK)
			lt = "UNSPEC_LINK";
		else if (link_type == OLSR_ASYM_LINK)
			lt = "ASYM_LINK";
		else if (link_type == OLSR_SYM_LINK)
			lt = "SYM_LINK";
		else if (link_type == OLSR_LOST_LINK)
			lt = "LOST_LINK";
		else
			lt = "UNKNOWN (likely a bug!)";
		
		fprintf(out, "\tlink_code = %s - %s\n\tlink_msg_size = %d\n",
			nt,
			lt,
			msg.link_msg_size());
		printf("\tlink_code = %s - %s\n\tlink_msg_size = %d\n",
			nt,
			lt,
			msg.link_msg_size());
	
		for (int j = 0; j < msg.count; j++){
			fprintf(out, "\tnb_iface_addr = %d\n", msg.nb_iface_addr(j));
			printf("\tnb_iface_addr = %d\n", msg.nb_iface_addr(j));}
	}
}