void
OLSR::mac_failed(Packet* p) {
	double now		= CURRENT_TIME;
	struct hdr_ip* ih	= HDR_IP(p);
	struct hdr_cmn* ch	= HDR_CMN(p);
	
	debug("%f: Node %d MAC Layer detects a breakage on link to %d\n",
		now,
		OLSR::node_id(ra_addr()),
		OLSR::node_id(ch->next_hop()));
	
	if ((u_int32_t)ih->daddr() == IP_BROADCAST) {
		drop(p, DROP_RTR_MAC_CALLBACK);
		return;
	}
	
	OLSR_link_tuple* link_tuple = state_.find_link_tuple(ch->next_hop());
	if (link_tuple != NULL) {
		link_tuple->lost_time()	= now + OLSR_NEIGHB_HOLD_TIME;
		link_tuple->time()	= now + OLSR_NEIGHB_HOLD_TIME;
		nb_loss(link_tuple);
	}
	drop(p, DROP_RTR_MAC_CALLBACK);
}