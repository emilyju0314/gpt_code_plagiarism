SatNode* LinkHandoffMgr::get_peer(SatLinkHead* slhp)
{
	SatChannel *schan_;
	Phy *remote_phy_;

	schan_ = (SatChannel*) slhp->phy_tx()->channel();
	if (schan_ == 0)
		return 0; // Link is not currently connected
	remote_phy_ = schan_->ifhead_.lh_first; 
	if (remote_phy_ == 0) {
		// this is not an error as far as satellite GSL endpoints
		// appear to be concerned.
		// Commented out for drawing GSL links in dumpSats()
		// in satnode.cc
		// printf("Error:  node %d's tx phy ", slhp->node()->address());
		// printf("connected to channel with no receivers\n");
		return 0;
	}
	if (remote_phy_->nextchnl()) {
		printf("Error:  This ISL channel has more than one target\n");
		return 0;
	}
	
	return ( (SatNode*) remote_phy_->head()->node());
}