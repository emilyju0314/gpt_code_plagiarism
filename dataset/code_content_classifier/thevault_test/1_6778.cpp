void SatNode::dumpSats()
{
	SatNode *snodep, *peer_snodep;
	SatPosition *sposp, *peer_sposp;
	PolarSatPosition *polar_sposp;
	SatLinkHead *slhp;
	int linktype;

        printf("\nDumping satellites at time %.2f\n\n", NOW);
        for (snodep= (SatNode*) Node::nodehead_.lh_first; snodep; 
		snodep = (SatNode*) snodep->nextnode()) {
		if (!SatNode::IsASatNode(snodep->address()))
			continue;
		sposp = snodep->position();
                printf("%d\t%.2f\t%.2f", snodep->address(), 
		    RAD_TO_DEG(SatGeometry::get_latitude(sposp->coord())), 
		    RAD_TO_DEG(SatGeometry::get_longitude(sposp->coord())));
		// If SatNode is polar, append plane information
		if (sposp->type()==POSITION_SAT_POLAR) {
			polar_sposp = (PolarSatPosition*) snodep->position();
			printf ("\t%d", polar_sposp->plane());
		} else if (sposp->type()==POSITION_SAT_GEO) {
			printf ("\tGEO");
		} else if (sposp->type()==POSITION_SAT_TERM) {
			printf ("\tTERM");
		}
		printf("\n");
	}
        printf("\n");
        // Dump satellite links
        // There is a static list of address classifiers //QQQ
        printf("Links:\n");
        for (snodep = (SatNode*) Node::nodehead_.lh_first; snodep; 
		snodep = (SatNode*) snodep->nextnode()) {
		if (!SatNode::IsASatNode(snodep->address()))
			continue;
		// XXX Not all links necessarily satlinks
		for (slhp = (SatLinkHead*) snodep->linklisthead_.lh_first; 
		    slhp; slhp = (SatLinkHead*) slhp->nextlinkhead() ) {
			linktype = slhp->type();
                	if (linktype == LINK_GENERIC)
                	        continue;
			if (!slhp->linkup_)
				continue;
                        // Link is up.
			// Print out source and dest coordinates.
			sposp = snodep->position();
			peer_snodep = hm_->get_peer(slhp);
			if (peer_snodep == 0)
				continue; // this link interface is not attached
			// need something in here for txs.
			peer_sposp = peer_snodep->position();
                        printf("%.2f\t%.2f\t%.2f\t%.2f\t%d\n", 
			 RAD_TO_DEG(SatGeometry::get_latitude(sposp->coord())),
			 RAD_TO_DEG(SatGeometry::get_longitude(sposp->coord())),
			 RAD_TO_DEG(SatGeometry::get_latitude(peer_sposp->coord())), 
			 RAD_TO_DEG(SatGeometry::get_longitude(peer_sposp->coord())),
			 linktype);
		}
	}
	printf("\nDumped satellites at time %.2f\n\n", NOW);
}