void
OLSR::forward_data(Packet* p) {
	struct hdr_cmn* ch	= HDR_CMN(p);
	struct hdr_ip* ih	= HDR_IP(p);

	if (ch->direction() == hdr_cmn::UP &&
		((u_int32_t)ih->daddr() == IP_BROADCAST || ih->daddr() == ra_addr())) {
		dmux_->recv(p, 0);
		return;
	}
	else {
		ch->direction()	= hdr_cmn::DOWN;
		ch->addr_type()	= NS_AF_INET;
		if ((u_int32_t)ih->daddr() == IP_BROADCAST)
			ch->next_hop()	= IP_BROADCAST;
		else {
			OLSR_rt_entry* entry = rtable_.lookup(ih->daddr());
			if (entry == NULL) {
				debug("%f: Node %d can not forward a packet destined to %d\n",
					CURRENT_TIME,
					OLSR::node_id(ra_addr()),
					OLSR::node_id(ih->daddr()));
				drop(p, DROP_RTR_NO_ROUTE);
				return;
			}
			else {
				entry = rtable_.find_send_entry(entry);
				assert(entry != NULL);
				ch->next_hop() = entry->next_addr();
				if (use_mac()) {
					ch->xmit_failure_	= olsr_mac_failed_callback;
					ch->xmit_failure_data_	= (void*)this;
				}
			}
		}

		Scheduler::instance().schedule(target_, p, 0.0);
	}
}