bool LsRouting::receiveLSA(int senderId, LsMessage* msgPtr)
{
	if (msgPtr == NULL) 
		return false;
	u_int32_t msgId = msgPtr->messageId_;
	int originNodeId = msgPtr->originNodeId_;

	sendAck(senderId, LS_MSG_LSAACK, originNodeId, msgId);
       
	if ((originNodeId == myNodeId_) ||
	     !lsaHistory_.isNewMessage(*msgPtr)) 
		return false; 

	// looks like we've got a new message LSA
	int peerId;
	if ((peerIdListPtr_ != NULL) && (myNodePtr_ != NULL)) {
		// forwards to peers whose links are up, except the sender 
		// and the originator 
		for (LsNodeIdList::iterator itr = peerIdListPtr_->begin();
		     itr != peerIdListPtr_->end(); itr++) {
			peerId = *itr;
			if ((peerId == originNodeId) || (peerId == senderId))
				continue; 
			if (isUp(peerId) && ((peerId) != senderId)) {
				ackManager_.messageOut(peerId, *msgPtr);
				myNodePtr_->sendMessage(peerId, msgId);
			}
		}
	}

	// Get the content of the message 
	if (msgPtr->contentPtr_ == NULL) 
		return false;
	bool changed = linkStateDatabase_.update(msgPtr->originNodeId_,
						 *(msgPtr->lslPtr_));
	if (changed)
		// linkstate database has changed, re-compute routes
		computeRoutes();
	return changed;
}