void
Agent::initpkt(Packet* p) const
{
	hdr_cmn* ch = hdr_cmn::access(p);
	ch->uid() = uidcnt_++;
	ch->ptype() = type_;
	ch->size() = size_;
	ch->timestamp() = Scheduler::instance().clock();
	ch->iface() = UNKN_IFACE.value(); // from packet.h (agent is local)
	ch->direction() = hdr_cmn::NONE;

	ch->error() = 0;	/* pkt not corrupt to start with */

	hdr_ip* iph = hdr_ip::access(p);
	iph->saddr() = here_.addr_;
	iph->sport() = here_.port_;
	iph->daddr() = dst_.addr_;
	iph->dport() = dst_.port_;
	
	//DEBUG
	//if (dst_ != -1)
	//  printf("pl break\n");
	
	iph->flowid() = fid_;
	iph->prio() = prio_;
	iph->ttl() = defttl_;

	hdr_flags* hf = hdr_flags::access(p);
	hf->ecn_capable_ = 0;
	hf->ecn_ = 0;
	hf->eln_ = 0;
	hf->ecn_to_echo_ = 0;
	hf->fs_ = 0;
	hf->no_ts_ = 0;
	hf->pri_ = 0;
	hf->cong_action_ = 0;
	hf->qs_ = 0;
#ifdef HAVE_STL

 	hdr_nv* nv = hdr_nv::access(p);
 	if (0)
		printf("Off hdr_nv %d, ip_hdr %d myaddr %d\n",
		       hdr_nv::offset(), hdr_ip::offset(), here_.addr_);
 	NixNode* pNixNode = NixNode::GetNodeObject(here_.addr_);
	// 	if (0)
	//		printf("Node Object %p\n", reinterpret_cast<void *>(pNixNode) );
 	if (pNixNode) { 
 		// If we get non-null, indicates nixvector routing in use
 		// Delete any left over nv in the packet
 		// Get a nixvector to the target (may create new)
 		NixVec* pNv = pNixNode->GetNixVector(dst_.addr_);
 		pNv->Reset();
 		nv->nv() = pNv; // And set the nixvec in the packet
 		nv->h_used = 0; // And reset used portion to 0
 	}
#endif //HAVE_STL
}