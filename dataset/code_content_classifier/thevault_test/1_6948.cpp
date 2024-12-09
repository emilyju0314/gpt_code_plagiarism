bool LsRouting::receiveTopo(int neighborId, LsMessage * msgPtr)
{
	// TODO
	bool changed = false;
	// send Ack 
	sendAck(neighborId, LS_MSG_TPMACK, neighborId, 
		msgPtr->sequenceNumber_);
	// check if it's a new message
	if (!tpmHistory_.isNewMessage(*msgPtr))
		return false;

	if (msgPtr->topoPtr_ == NULL)
		return false;
	// Compare with my own database
	for (LsTopoMap::const_iterator recItr = msgPtr->topoPtr_->begin();
	     recItr != msgPtr->topoPtr_->end(); recItr++) {

		if ((*recItr).first == myNodeId_)
			// Don't need peer to tell me my own link state 
			continue; 
		// find my own record of the LSA of the node being examined
		LsLinkStateList* myRecord = 
			linkStateDatabase_.findPtr((*recItr).first);

		if ((myRecord == NULL) || // we don't have it
		    myRecord->empty() ||
		    // or we have an older record
		    ((*(myRecord->begin())).sequenceNumber_ <
		     (*((*recItr).second.begin())).sequenceNumber_) ||
		    ((*(myRecord->begin())).sequenceNumber_ - 
		     (*((*recItr).second.begin())).sequenceNumber_ > 
		     LS_WRAPAROUND_THRESHOLD)) {

			// Update our database
			changed = true;
			if (myRecord == NULL)
				linkStateDatabase_.insert((*recItr).first, 
							 (*recItr).second);
			else 
				*myRecord = (*recItr).second ;
			// Regenerate the LSA message and send to my peers, 
			// except the sender of the topo and the 
			// originator of the LSA
			regenAndSend (/* to except */neighborId, 
				      /* originator */(*recItr).first, 
				      /* the linkstateList */(*recItr).second);
		}
	}
	if (changed)
		computeRoutes();
	// if anything relevant has changed, recompute routes
	return changed;
}