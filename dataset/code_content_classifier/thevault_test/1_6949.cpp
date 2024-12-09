void LsRouting::regenAndSend(int exception, int origin, 
			     const LsLinkStateList& lsl)
{
	if (lsl.empty())
		ls_error("lsl is empty, in LsRouting::regenAndSend.\n");
	LsLinkStateList* newLSLptr = new LsLinkStateList(lsl);
	if (newLSLptr == NULL) { 
		ls_error("Can't get new link state list, in "
			 "LsRouting::sendLinkStates\n");
		return;
	}

	// replicate the LSA 
	LsMessage* msgPtr =  msgctr().newMessage(origin, LS_MSG_LSA);
	msgPtr->sequenceNumber_ = (*lsl.begin()).sequenceNumber_;
	msgPtr->originNodeId_ = origin;

	for (LsNodeIdList::iterator itr = peerIdListPtr_->begin();
	     itr != peerIdListPtr_->end(); itr++) {
		if ((*itr == origin) || (*itr == exception) || !isUp(*itr))
			continue; 
		bufferedSend(*itr, msgPtr);
		// debug 
//  		cout << "Node " << myNodeId << " regenAndSend " 
//  		     << (*(lsl.begin())).sequenceNumber << " from origin  " << origin 
//  		     << " to peer " << *itr << endl;
	}
}