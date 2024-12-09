void
OLSR_printer::print_olsr_msg(FILE* out, OLSR_msg& msg) {
	char *msg_type;
	
	switch (msg.msg_type()) {
		case OLSR_HELLO_MSG:
			msg_type = "HELLO";
			break;
		case OLSR_TC_MSG:
			msg_type = "TC";
			break;
		case OLSR_MID_MSG:
			msg_type = "MID";
			break;
		default:
			msg_type = "UNKNOWN (likely a bug!)";
	}
	
	fprintf(out,
		"\ttype = %s\n\tvtime = %.2f\n\tmsg_size = %d\n\t"
		"orig_addr = %d\n\tttl = %d\n\thop_count = %d\n\t"
		"msg_seq_num = %d\n",
		msg_type,
		OLSR::emf_to_seconds(msg.vtime()),
		msg.msg_size(),
		msg.orig_addr(),
		msg.ttl(),
		msg.hop_count(),
		msg.msg_seq_num());
	printf(	"\ttype = %s\n\tvtime = %.2f\n\tmsg_size = %d\n\t"
		"orig_addr = %d\n\tttl = %d\n\thop_count = %d\n\t"
		"msg_seq_num = %d\n",
		msg_type,
		OLSR::emf_to_seconds(msg.vtime()),
		msg.msg_size(),
		msg.orig_addr(),
		msg.ttl(),
		msg.hop_count(),
		msg.msg_seq_num());
	
	if (msg.msg_type() == OLSR_HELLO_MSG)
		print_olsr_hello(out, msg.hello());
	else if (msg.msg_type() == OLSR_TC_MSG)
		print_olsr_tc(out, msg.tc());
	else if (msg.msg_type() == OLSR_MID_MSG)
		print_olsr_mid(out, msg.mid());
}