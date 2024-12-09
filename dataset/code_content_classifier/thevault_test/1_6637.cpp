void
OLSR::send_mid() {
	OLSR_msg msg;
	msg.msg_type()		= OLSR_MID_MSG;
	msg.vtime()		= OLSR::seconds_to_emf(OLSR_MID_HOLD_TIME);
	msg.orig_addr()		= ra_addr();
	msg.ttl()		= 255;
	msg.hop_count()		= 0;
	msg.msg_seq_num()	= msg_seq();
	
	msg.mid().count		= 0;
	//foreach iface in this_node do
	//	msg.mid().iface_addr(i) = iface
	//	msg.mid().count++
	//done
	
	msg.msg_size()		= msg.size();
	
	enque_msg(msg, JITTER);
}