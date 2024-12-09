bool LsRouting::receiveMessage (int senderId, u_int32_t msgId)
{
	if (senderId == LS_INVALID_NODE_ID)
		return false;
	LsMessage* msgPtr = msgctr().retrieveMessagePtr(msgId);
	if (msgPtr == NULL)
		return false;

	// A switch statement to see the type.
	// and handle differently
	bool retCode = false;
	switch (msgPtr->type_){
	case LS_MSG_LSM:
		// not supported yet
		break;
	case LS_MSG_TPM:
		retCode = receiveTopo (senderId, msgPtr);
		break;
	case LS_MSG_LSA:  // Link State Update 
		retCode = receiveLSA (senderId, msgPtr);
		break;
	case LS_MSG_LSAACK: 
	case LS_MSG_TPMACK: 
		receiveAck(senderId, msgPtr);
		msgctr().deleteMessage(msgId);
		break;
	default:
		break;
	}
	return retCode;
}