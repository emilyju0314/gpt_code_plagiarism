int TermLinkHandoffMgr::handoff()
{
	coordinate sat_coord, earth_coord;
	SatLinkHead* slhp;
	SatNode *peer_; // Polar satellite at opposite end of the GSL
	SatNode *best_peer_ = 0; // Best found peer for handoff
	Node *nodep;  // Pointer used in searching the list of nodes
	PolarSatPosition *nextpos_;
	int link_changes_flag_ = FALSE; // Flag indicating change took place 
	int restart_timer_flag_ = FALSE; // Restart timer only if polar links
	double found_elev_ = 0;  //``Flag'' indicates whether handoff can occur 
	double best_found_elev_ = 0; 
	double mask_ = DEG_TO_RAD(TermLinkHandoffMgr::elevation_mask_);

	earth_coord = ((SatNode *)node_)->position()->coord();
	// Traverse the linked list of link interfaces
	for (slhp = (SatLinkHead*) node_->linklisthead().lh_first; slhp; 
	    slhp = (SatLinkHead*) slhp->nextlinkhead() ) {
		if (slhp->type() == LINK_GSL_GEO || 
		    slhp->type() == LINK_GENERIC)
			continue;
		if (slhp->type() != LINK_GSL_POLAR) {
			printf("Error: Terminal link type ");
			printf("not valid %d NOW %f\n", slhp->type(), NOW);
			exit(1);
		}
		// The link is a GSL_POLAR link-- should be one receive 
		// interface on it
		restart_timer_flag_ = TRUE;
		peer_ = get_peer(slhp);
		if (peer_) {
			sat_coord = peer_->position()->coord();
			if (!SatGeometry::check_elevation(sat_coord, 
			    earth_coord, mask_) && slhp->linkup_) {
				slhp->linkup_ = FALSE;
				link_changes_flag_ = TRUE;
				// Detach receive link interface from channel
				// Next line removes phy from linked list
				//   of interfaces attached to channel
				slhp->phy_rx()->removechnl();
				// Set our channel pointers to NULL
				slhp->phy_tx()->setchnl(0);
				slhp->phy_rx()->setchnl(0);
				// wired-satellite integration
				if (SatRouteObject::instance().wiredRouting()) {
					Tcl::instance().evalf("[Simulator instance] sat_link_destroy %d %d", slhp->phy_tx()->node()->address(), peer_->address());
					// Must do this bidirectionally
					Tcl::instance().evalf("[Simulator instance] sat_link_destroy %d %d", peer_->address(), slhp->phy_tx()->node()->address());
				}
			}
		}
		if (!slhp->linkup_) {
			// If link is down, see if we can use another satellite
			// 
			// As an optimization, first check the next satellite 
			// coming over the horizon.  Next, consider all 
			// remaining satellites.
			// 
			if (peer_) {
				// Next satellite
				nextpos_ = ((PolarSatPosition*) 
				    peer_->position())->next();
				if (nextpos_) {
					sat_coord = nextpos_->coord();
					found_elev_ = SatGeometry::check_elevation(sat_coord, earth_coord, mask_);
					if (found_elev_)
						peer_ = (SatNode*) nextpos_->node();
				}
			}
			// Next, check all remaining satellites if not found
			if (!found_elev_) {
				for (nodep=Node::nodehead_.lh_first; nodep;
				    nodep = nodep->nextnode()) {
					if (!SatNode::IsASatNode(nodep->address()))
						continue;
					peer_ = (SatNode*) nodep;
					if (peer_->position() && 
					    (peer_->position()->type() != 
					    POSITION_SAT_POLAR))
						    continue;
					sat_coord = 
					    peer_->position()->coord();
					found_elev_ = SatGeometry::check_elevation(sat_coord, earth_coord, mask_);
					if (found_elev_ > best_found_elev_) {
					    best_peer_ = peer_;
					    best_found_elev_ = found_elev_;
					}
				}
				if (best_found_elev_ > 0.0) {
					assert (best_peer_ != 0);
					peer_ = best_peer_;
					found_elev_ = best_found_elev_;
				}
			}
			if (found_elev_) {
				slhp->linkup_ = TRUE;
				link_changes_flag_ = TRUE;
				// Point slhp->phy_tx to peer_'s inlink
				slhp->phy_tx()->setchnl(peer_->uplink());
				// Point slhp->phy_rx to peer_'s outlink and
				// add phy_rx to the channels list of phy's
				slhp->phy_rx()->setchnl(peer_->downlink());
				// Add phy to channel's linked list of i/fces
				slhp->phy_rx()->insertchnl(&(peer_->downlink()->ifhead_));
			}
		}
	}
	if (link_changes_flag_) { 
		SatRouteObject::instance().recompute();
	}
	if (restart_timer_flag_) {
		// If we don't have polar GSLs, don't reset the timer
		if (handoff_randomization_) {
			timer_.resched(term_handoff_int_ + 
			    handoff_rng_.uniform(-1 * term_handoff_int_/2, 
			    term_handoff_int_/2));
		} else
			timer_.resched(term_handoff_int_);
	}
        return link_changes_flag_;
}