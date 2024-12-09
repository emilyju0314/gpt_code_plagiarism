SatLinkHead* LinkHandoffMgr::get_peer_linkhead(SatLinkHead* slhp)
{
	SatChannel *schan_;
	Phy *remote_phy_;

	schan_ = (SatChannel*) slhp->phy_tx()->channel();
	if (schan_ == 0) {
		printf("Error:  get_peer_linkhead called for a non-");
		printf("connected link on node %d\n", slhp->node()->address());
		return 0; // Link is not currently connected
	}
	remote_phy_ = schan_->ifhead_.lh_first; 
	if (remote_phy_ == 0) {
		printf("Error:  node %d's tx phy ", slhp->node()->address());
		printf("connected to channel with no receivers\n");
		return 0;
	}
	if (remote_phy_->nextchnl()) {
		printf("Error:  This ISL channel has more than one target\n");
		return 0;
	}
	return ( (SatLinkHead*) remote_phy_->head());
}