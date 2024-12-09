void
OLSR::send_tc() {
	OLSR_msg msg;
	msg.msg_type()		= OLSR_TC_MSG;
	msg.vtime()		= OLSR::seconds_to_emf(OLSR_TOP_HOLD_TIME);
	msg.orig_addr()		= ra_addr();
	msg.ttl()		= 255;
	msg.hop_count()		= 0;
	msg.msg_seq_num()	= msg_seq();
	
	msg.tc().ansn()		= ansn_;
	msg.tc().reserved()	= 0;
	msg.tc().count		= 0;
	
	for (mprselset_t::iterator it = mprselset().begin(); it != mprselset().end(); it++) {
		OLSR_mprsel_tuple* mprsel_tuple = *it;
		int count = msg.tc().count;

		assert(count >= 0 && count < OLSR_MAX_ADDRS);
		msg.tc().nb_main_addr(count) = mprsel_tuple->main_addr();
		msg.tc().count++;
	}

	msg.msg_size()		= msg.size();
	
	enque_msg(msg, JITTER);
}