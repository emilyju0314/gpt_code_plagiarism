void
OLSR::process_hello(OLSR_msg& msg, nsaddr_t receiver_iface, nsaddr_t sender_iface) {
	assert(msg.msg_type() == OLSR_HELLO_MSG);

        link_sensing(msg, receiver_iface, sender_iface);
	populate_nbset(msg);
	populate_nb2hopset(msg);
	mpr_computation();
	populate_mprselset(msg);
}