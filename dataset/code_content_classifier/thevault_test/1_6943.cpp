int LsRetransmissionManager::messageOut(int peerId, 
					const LsMessage& msg)
{
	LsUnackPeer* peerPtr = findPtr(peerId);
	if (peerPtr == NULL) {
		iterator itr = insert(peerId, LsUnackPeer(this, peerId));
		if (itr == end()) { 
			ls_error ("Can't insert."); 
		}
		peerPtr = &((*itr).second);
	}
	LsIdSeq* idSeqPtr;
	switch (msg.type_) {
	case LS_MSG_TPM:
		peerPtr->tpmSeq_ = msg.sequenceNumber_;
		break;
	case LS_MSG_LSA:
		idSeqPtr =  peerPtr->lsaMap_.findPtr(msg.originNodeId_);
		if (idSeqPtr == NULL)
			peerPtr->lsaMap_.insert(msg.originNodeId_, 
				 LsIdSeq(msg.messageId_, msg.sequenceNumber_));
		else {
			idSeqPtr->msgId_ = msg.messageId_;
			idSeqPtr->seq_ = msg.sequenceNumber_;
		}
		break;
	case LS_MSG_TPMACK:
	case LS_MSG_LSAACK:
	case LS_MSG_LSM:
	default:
		// nothing, just to avoid compiler warning
		break;
	}
 
	// reschedule timer to allow account for this latest message
	peerPtr->timer_.resched(peerPtr->rtxTimeout_);
  
	return 0;
}