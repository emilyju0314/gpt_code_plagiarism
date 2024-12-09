int Port::Say(const char *buf)
{
	int result = YARP_FAIL;
	if (self_id == NULL)
	{
		if (protocol_type == YARP_MCAST)
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), YARP_UDP);
			self_id->setServiceType (YARP_TCP);
			self_id->setRequireAck(require_ack);
			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
		else
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), protocol_type);
			if (self_id->getServiceType() != YARP_QNET)
				self_id->setServiceType (YARP_TCP);
			self_id->setRequireAck(require_ack);

			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
	}
	else
	/// silly but to guarantee self_id is !NULL.
	if (self_id != NULL && !self_id->isValid())
	{
		if (protocol_type == YARP_MCAST)
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), YARP_UDP);
			self_id->setServiceType (YARP_TCP);
			self_id->setRequireAck(require_ack);
			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
		else
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), protocol_type);
			if (self_id->getServiceType() != YARP_QNET)
				self_id->setServiceType (YARP_TCP);
			self_id->setRequireAck(require_ack);

			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
	}

	if (self_id->isValid())
	{
		result = SayServer(*self_id, buf);
	}

	/// deletes the endpoint.
	YARPEndpointManager::Close (*self_id);

	YARPNameService::DeleteName (self_id);
	self_id = NULL;
	return result;
}