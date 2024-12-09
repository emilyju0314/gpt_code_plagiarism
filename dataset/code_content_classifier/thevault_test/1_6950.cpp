void LsRouting::sendTopo(int neighborId) 
{
	// if we've gone so far, messageCenterPtr should not be null, 
	// don't check
	LsMessage* msgPtr= msgctr().newMessage(myNodeId_, LS_MSG_TPM);
	// XXX, here we are going to send the pointer that points
	// to my own topo, because sending the who topomap is too costly in
	// simulation
	msgPtr->contentPtr_ = &linkStateDatabase_;
	bufferedSend(neighborId, msgPtr);
}