void SatLL::sendDown(Packet* p)
{	
	hdr_cmn *ch = HDR_CMN(p);
	hdr_ll *llh = HDR_LL(p);
	
	char *mh = (char*)p->access(hdr_mac::offset_);
	int peer_mac_;
	SatChannel* satchannel_;

	llh->seqno_ = ++seqno_;
	llh->lltype() = LL_DATA;

	getRoute(p);
	
	// Set mac src, type, and dst
	mac_->hdr_src(mh, mac_->addr());
	mac_->hdr_type(mh, ETHERTYPE_IP); // We'll just use ETHERTYPE_IP
	
	nsaddr_t dst = ch->next_hop();
	// a value of -1 is IP_BROADCAST
	if (dst < -1) {
		printf("Error:  next_hop_ field not set by routing agent\n");
		exit(1);
	}

	switch(ch->addr_type()) {

	case NS_AF_INET:
	case NS_AF_NONE:
		if (IP_BROADCAST == (u_int32_t) dst)
			{
			mac_->hdr_dst((char*) HDR_MAC(p), MAC_BROADCAST);
			break;
		}
		/* 
		 * Here is where arp would normally occur.  In the satellite
		 * case, we don't arp (for now).  Instead, use destination
		 * address to find the mac address corresponding to the
		 * peer connected to this channel.  If someone wants to
		 * add arp, look at how the wireless code does it.
		 */ 
		// Cache latest value used
		if (dst == arpcachedst_) {
			mac_->hdr_dst((char*) HDR_MAC(p), arpcache_);
			break;
		}
		// Search for peer's mac address (this is the pseudo-ARP)
		satchannel_ = (SatChannel*) channel();
		peer_mac_ = satchannel_->find_peer_mac_addr(dst);
		if (peer_mac_ < 0 ) {
			printf("Error:  couldn't find dest mac on channel ");
			printf("for src/dst %d %d at NOW %f\n", 
			    ch->last_hop_, dst, NOW); 
			exit(1);
		} else {
			mac_->hdr_dst((char*) HDR_MAC(p), peer_mac_);
			arpcachedst_ = dst;
			arpcache_ = peer_mac_;
			break;
		} 

	default:
		printf("Error:  addr_type not set to NS_AF_INET or NS_AF_NONE\n");
		exit(1);
	}
	
	// let mac decide when to take a new packet from the queue.
	Scheduler& s = Scheduler::instance();
	s.schedule(downtarget_, p, delay_);
}