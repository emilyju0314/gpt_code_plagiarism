int SatChannel::find_peer_mac_addr(int dst)
{
	Phy *n;
	Channel* chan_;
	chan_ = this;
	n = ifhead_.lh_first; 
	if (n->head()->type() == LINK_GSL_REPEATER) {
		SatLinkHead* slh = (SatLinkHead*) n->head();
		chan_ = slh->phy_tx()->channel();
	}
	for(n = chan_->ifhead_.lh_first; n; n = n->nextchnl() ) {
		if (n->node()->address() == dst) {
			return (((SatMac*) n->uptarget())->addr());
		}
	}
	return -1;
}