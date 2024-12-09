int _SocketThreadMultiTcp::reuse(const YARPUniqueNameSock* remid, const YARPUniqueNameID* socket, int port)
{
	// remid must be always TCP.
	ACE_ASSERT (remid->getServiceType() == YARP_TCP);

	clearOldAddr ();

	// making sure semaphores are in the right state.
	if (_wakeup.PollingWait())
		ACE_DEBUG ((LM_DEBUG, "****** reuse found _wakeup != 0\n"));

	if (port != 0)
	{
		// this is fine but the actual remote is the TCP here...
		// this gets the right value only after the first recv, no alternatives.
		_remote_endpoint = *remid;
		_port = port;

		// not quite needed for the addr itself (just stores the protocol -TCP-).
		_socket_addr = new YARPUniqueNameSock (*(YARPUniqueNameSock*)socket);
		ACE_ASSERT (_socket_addr != NULL);

		// externally provided during creation.
		ACE_ASSERT (_stream != NULL);

		if (_stream->get_handle() == ACE_INVALID_HANDLE)
		{
			_available = 1;
			return YARP_FAIL;
		}

		// since socket is NULL use the _stream ID.
		_socket_addr->setRawIdentifier (_stream->get_handle());
		_available = 0;
	}
	else
	{
		_available = 1;
		_remote_endpoint.invalidate();
		_socket_addr = NULL;

		if (_stream != NULL)
		{
			_stream->close ();
			delete _stream;
			_stream = NULL;
		}

		return YARP_FAIL;
	}

	return YARP_OK;
}