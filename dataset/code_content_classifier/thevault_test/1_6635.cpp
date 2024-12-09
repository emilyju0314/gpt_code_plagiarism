void
OLSR::send_hello() {
	OLSR_msg msg;
	double now		= CURRENT_TIME;
	msg.msg_type()		= OLSR_HELLO_MSG;
	msg.vtime()		= OLSR::seconds_to_emf(OLSR_NEIGHB_HOLD_TIME);
	msg.orig_addr()		= ra_addr();
	msg.ttl()		= 1;
	msg.hop_count()		= 0;
	msg.msg_seq_num()	= msg_seq();
	
	msg.hello().reserved()		= 0;
	msg.hello().htime()		= OLSR::seconds_to_emf(hello_ival());
	msg.hello().willingness()	= willingness();
	msg.hello().count		= 0;

        printf("----------Send OLSR Hello Message----------------\n");
	printf("now: %d\n",now);
	printf("msg.msg_type(): %d\n",msg.msg_type());
	printf("msg.vtime(): %d\n",msg.vtime());
	printf("msg.orig_addr(): %d\n",msg.orig_addr());
	printf("msg.ttl(): %d\n",msg.ttl());
	printf("msg.hop_count(): %d\n",msg.hop_count());
	printf("msg.msg_seq_num(): %d\n",msg.msg_seq_num());
	printf("msg.hello().reserved(): %d\n",msg.hello().reserved());
	printf("msg.hello().htime(): %d\n",msg.hello().htime());
	printf("msg.hello().willingness(): %d\n",msg.hello().willingness());
	printf("msg.hello().count: %d\n",msg.hello().count);
	
	map<u_int8_t, int> linkcodes_count;
	for (linkset_t::iterator it = linkset().begin(); it != linkset().end(); it++) {
		OLSR_link_tuple* link_tuple = *it;
		if (link_tuple->local_iface_addr() == ra_addr() && link_tuple->time() >= now) {
			u_int8_t link_type, nb_type, link_code;
			
			// Establishes link type
			if (use_mac() && link_tuple->lost_time() >= now)
				link_type = OLSR_LOST_LINK;
			else if (link_tuple->sym_time() >= now)
				link_type = OLSR_SYM_LINK;
			else if (link_tuple->asym_time() >= now)
				link_type = OLSR_ASYM_LINK;
			else
				link_type = OLSR_LOST_LINK;
			// Establishes neighbor type.
			if (state_.find_mpr_addr(get_main_addr(link_tuple->nb_iface_addr())))
				nb_type = OLSR_MPR_NEIGH;
			else {
				bool ok = false;
				for (nbset_t::iterator nb_it = nbset().begin();
					nb_it != nbset().end();
					nb_it++) {
					OLSR_nb_tuple* nb_tuple = *nb_it;
					if (nb_tuple->nb_main_addr() == link_tuple->nb_iface_addr()) {
						if (nb_tuple->status() == OLSR_STATUS_SYM)
							nb_type = OLSR_SYM_NEIGH;
						else if (nb_tuple->status() == OLSR_STATUS_NOT_SYM)
							nb_type = OLSR_NOT_NEIGH;
						else {
							fprintf(stderr, "There is a neighbor tuple"
								" with an unknown status!\n");
							exit(1);
						}
						ok = true;
						break;
					}
				}
				if (!ok) {
					fprintf(stderr, "Link tuple has no corresponding"
						" Neighbor tuple\n");
					exit(1);
				}
			}

			int count = msg.hello().count;
			link_code = (link_type & 0x03) | ((nb_type << 2) & 0x0f);
			map<u_int8_t, int>::iterator pos = linkcodes_count.find(link_code);
			if (pos == linkcodes_count.end()) {
				linkcodes_count[link_code] = count;
				assert(count >= 0 && count < OLSR_MAX_HELLOS);
				msg.hello().hello_msg(count).count = 0;
				msg.hello().hello_msg(count).link_code() = link_code;
				msg.hello().hello_msg(count).reserved() = 0;
				msg.hello().count++;
			}
			else
				count = (*pos).second;
			
			int i = msg.hello().hello_msg(count).count;
			assert(count >= 0 && count < OLSR_MAX_HELLOS);
			assert(i >= 0 && i < OLSR_MAX_ADDRS);
			
			msg.hello().hello_msg(count).nb_iface_addr(i) =
				link_tuple->nb_iface_addr();
			msg.hello().hello_msg(count).count++;
			msg.hello().hello_msg(count).link_msg_size() =
				msg.hello().hello_msg(count).size();
		}
	}
	
	msg.msg_size() = msg.size();
	
	enque_msg(msg, JITTER);
}