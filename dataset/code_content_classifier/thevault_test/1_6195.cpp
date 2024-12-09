int _SocketThreadMultiShmem::reuse(const YARPUniqueNameSock* remid, const YARPUniqueNameID* socket, int port)
{
	// remid must be always TCP.
	ACE_ASSERT (remid->getServiceType() == YARP_TCP);

	clearOldAddr ();

	// making sure semaphores are in the right state.
	if (_wakeup.PollingWait())
		ACE_DEBUG ((LM_DEBUG, "****** reuse found _wakeup != 0\n"));

	if (port != 0)
	{
		// this is fine but the actual remote is the TCP here and not the UDP.
		// this gets the right value only after the first recv, no alternatives.

		_remote_endpoint = *remid;
		_port = port;

		_socket_addr = new YARPUniqueNameMem (*(YARPUniqueNameMem*)socket);
		((YARPUniqueNameMem*)_socket_addr)->getAddressRef().set(port); // just in case 

		ACE_ASSERT (_socket_addr != NULL);

		_socket = new ACE_MEM_Acceptor (((YARPUniqueNameMem&)*_socket_addr).getAddressRef(), 1);
		ACE_ASSERT (_socket != NULL);

		// the size of the SHMEM buffer and the delivery strategy.
		_socket->init_buffer_size (2 * MAX_SHMEM_BUFFER);
		_socket->preferred_strategy (ACE_MEM_IO::Reactive);

		_socket_addr->setRawIdentifier (((ACE_MEM_Acceptor *)_socket)->get_handle());
		if (_socket_addr->getRawIdentifier() == ACE_INVALID_HANDLE)
		{
			_available = 1;
			return YARP_FAIL;
		}

		_available = 0;
	}
	else
	{
		_available = 1;
		_socket = NULL;
		_remote_endpoint.invalidate();
		_socket_addr = NULL;
	}

	return YARP_OK;
}