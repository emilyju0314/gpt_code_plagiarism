int LsRetransmissionManager::ackIn(int peerId, const LsMessage& msg)
{
	LsUnackPeer* peerPtr = findPtr(peerId);
	if ((peerPtr == NULL) ||
	    ((peerPtr->tpmSeq_ == LS_INVALID_MESSAGE_ID) &&
	    peerPtr->lsaMap_.empty()))
		// no pending ack for this neighbor 
		return 0;

	LsMap<int, LsIdSeq>::iterator itr;
	switch (msg.type_) {
	case LS_MSG_TPMACK:
		if (peerPtr->tpmSeq_ == msg.sequenceNumber_)
			// We've got the right ack, so erase the unack record
			peerPtr->tpmSeq_ = LS_INVALID_MESSAGE_ID;
		break;
	case LS_MSG_LSAACK:
		itr = peerPtr->lsaMap_.find(msg.originNodeId_);
		if ((itr != peerPtr->lsaMap_.end()) && 
		    ((*itr).second.seq_ == msg.sequenceNumber_)) 
			// We've got the right ack, so erase the unack record
			peerPtr->lsaMap_.erase(itr);
		break;
	case LS_MSG_TPM:
	case LS_MSG_LSA: 
	case LS_MSG_LSM:
	default:
		break;
	}

	if ((peerPtr->tpmSeq_ == LS_INVALID_MESSAGE_ID) &&
	    (peerPtr->lsaMap_.empty()))
		// No more pending ack, cancel timer
		peerPtr->timer_.cancel();

	// ack deleted in calling function LsRouting::receiveMessage
	return 0;
}