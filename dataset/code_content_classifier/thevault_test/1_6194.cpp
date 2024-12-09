int _SocketThreadMultiMcast::reuse(const YARPUniqueNameSock* remid, const YARPUniqueNameID* socket, int port)
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

		//
		// LATER: is this needed, shouldn't be already closed.
		_local_acceptor.close ();
		_port = port;

		YARPString myhostip = _remote_endpoint.getAddressRef().get_host_addr();
		ACE_INET_Addr local (port, myhostip.c_str());

		// opens the local socket (for termination).
		if (_local_acceptor.open (local, 1))
		{
			_available = 1;
			return YARP_FAIL;
		}

		_socket_addr = new YARPUniqueNameSock (*(YARPUniqueNameSock*)socket);
		ACE_ASSERT (_socket_addr != NULL);

		_socket = new ACE_SOCK_Dgram_Mcast;
		ACE_ASSERT (_socket != NULL);

		ACE_SOCK_Dgram_Mcast& mcast = *_socket;

		if (_remote_endpoint.getInterfaceName() != YARPString("default")) 
		{
			mcast.open (((YARPUniqueNameSock&)*_socket_addr).getAddressRef(), _remote_endpoint.getInterfaceName().c_str(), 1);
		} 
		else 
		{
			mcast.open (((YARPUniqueNameSock&)*_socket_addr).getAddressRef(), NULL, 1);
		}

		YARPNetworkObject::setSocketBufSize (mcast, MAX_PACKET);
		if (_remote_endpoint.getInterfaceName() != YARPString("default")) 
		{
			mcast.join (((YARPUniqueNameSock&)*_socket_addr).getAddressRef(), 1, _remote_endpoint.getInterfaceName().c_str());
		} 
		else 
		{
			mcast.join (((YARPUniqueNameSock&)*_socket_addr).getAddressRef(), 1, NULL);
		}

		if (mcast.get_handle() == ACE_INVALID_HANDLE)
		{
			_available = 1;
			return YARP_FAIL;
		}

		_socket_addr->setRawIdentifier (mcast.get_handle());
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