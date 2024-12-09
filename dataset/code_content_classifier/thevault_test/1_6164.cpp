int Port::SaySelfEnd(void)
{
	int result = YARP_FAIL;
	if (self_id == NULL && name.c_str()[0] != '\0')
	{
		if (protocol_type == YARP_MCAST)
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), YARP_UDP);
			self_id->setServiceType (YARP_TCP);

			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
		else
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), protocol_type);
			if (self_id->getServiceType() != YARP_QNET)
				self_id->setServiceType (YARP_TCP);

			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
	}
	else
	/// silly but to guarantee self_id is !NULL.
	if (self_id != NULL && !self_id->isValid() && name.c_str()[0] != '\0')
	{
		if (protocol_type == YARP_MCAST)
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), YARP_UDP);
			self_id->setServiceType (YARP_TCP);

			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
		else
		{
			self_id = YARPNameService::LocateName(name.c_str(), network_name.c_str(), protocol_type);
			if (self_id->getServiceType() != YARP_QNET)
				self_id->setServiceType (YARP_TCP);

			YARPEndpointManager::CreateOutputEndpoint (*self_id);
			YARPEndpointManager::ConnectEndpoints (*self_id, name);
		}
	}

	if (self_id != NULL)
	{
		if (self_id->isValid())
		{
			// need to make sure the detach message will be read,
			// even if other messages are arriving

			Relinquish();
			out_mutex.Wait();
			ignore_data = 1;
			out_mutex.Post();
			Relinquish();

			result = SendHelper (*self_id, NULL, 0, MSG_ID_DETACH_ALL);
		}

		Relinquish();
		/// wait for message to be received.
		complete_msg_thread.Wait();

		/// deletes the endpoint.
		YARPEndpointManager::Close (*self_id);

		YARPNameService::DeleteName (self_id);
		self_id = NULL;

		///YARPScheduler::yield();

		/// tell the main thread to complete the termination function.
		complete_terminate.Signal();

		YARPThread::Join ();
	}

	return result;
}