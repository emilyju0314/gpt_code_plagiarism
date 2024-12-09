void
OLSR::populate_nbset(OLSR_msg& msg) {
	OLSR_hello& hello = msg.hello();
	
	OLSR_nb_tuple* nb_tuple = state_.find_nb_tuple(msg.orig_addr());
	if (nb_tuple != NULL)
		nb_tuple->willingness() = hello.willingness();
}