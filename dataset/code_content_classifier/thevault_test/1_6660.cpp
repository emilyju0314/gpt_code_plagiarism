int
OLSR::degree(OLSR_nb_tuple* tuple) {
	int degree = 0;
	for (nb2hopset_t::iterator it = nb2hopset().begin(); it != nb2hopset().end(); it++) {
		OLSR_nb2hop_tuple* nb2hop_tuple = *it;
		if (nb2hop_tuple->nb_main_addr() == tuple->nb_main_addr()) {
			OLSR_nb_tuple* nb_tuple =
				state_.find_nb_tuple(nb2hop_tuple->nb_main_addr());
			if (nb_tuple == NULL)
				degree++;
		}
	}
	return degree;
}