SatLinkHead* LinkHandoffMgr::get_peer_next_linkhead(SatNode* np)
{
	LinkHead* lhp;
	SatLinkHead* slhp;
	for (lhp = np->linklisthead().lh_first; lhp; 
	    lhp = lhp->nextlinkhead() ) {
		slhp = (SatLinkHead*) lhp;
		if (slhp->type() == LINK_ISL_CROSSSEAM) {
			if (!slhp->phy_tx()->channel() && 
			    !slhp->phy_rx()->channel() ) 
				return slhp;
		}
	}
	printf("Error, couldn't find an empty crossseam stack for handoff\n");
	return 0;
}