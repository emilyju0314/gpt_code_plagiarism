OLSR::OLSR(nsaddr_t id) :	Agent(PT_OLSR),
				hello_timer_(this),
				tc_timer_(this),
				mid_timer_(this) {

	// Enable usage of some of the configuration variables from Tcl.
	//
	// Note: Do NOT change the values of these variables in the constructor
	// after binding them! The desired default values should be set in
	// ns-X.XX/tcl/lib/ns-default.tcl instead.
	bind("willingness_", &willingness_);
	bind("hello_ival_", &hello_ival_);
	bind("tc_ival_", &tc_ival_);
	bind("mid_ival_", &mid_ival_);
	bind_bool("use_mac_", &use_mac_);
	
	// Do some initializations
	ra_addr_	= id;
	pkt_seq_	= OLSR_MAX_SEQ_NUM;
	msg_seq_	= OLSR_MAX_SEQ_NUM;
	ansn_		= OLSR_MAX_SEQ_NUM;
	printf("ID : %d\n",id);
	printf("OLSR_MAX_SEQ_NUM : %d\n",OLSR_MAX_SEQ_NUM);
}