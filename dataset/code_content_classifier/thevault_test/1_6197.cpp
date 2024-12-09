ACE_HANDLE _SocketThreadListMulti::connect (const YARPUniqueNameSock& id)
{
	_local_addr = ((YARPUniqueNameSock&)id).getAddressRef();

	// for YARP2 flexibility, don't select a particular IP
#ifdef USE_YARP2
	ACE_INET_Addr flex;
	flex.set_port_number(_local_addr.get_port_number());
	_local_addr.set(flex);
#endif
	// YARP2 change finished

	_acceptor_socket.open (_local_addr, 1);	// reuse addr enabled.

	if (_acceptor_socket.get_handle() == ACE_INVALID_HANDLE)
	{
	  ACE_DEBUG ((LM_WARNING, "*** FAILED to open tcp connection (%s:%d)\n", _local_addr.get_host_addr(), _local_addr.get_port_number()));
	  ACE_DEBUG ((LM_WARNING, "*** --- This can happen if the requested socket-port is already in use.\n", _local_addr.get_host_addr(), _local_addr.get_port_number()));
	  ACE_DEBUG ((LM_WARNING, "*** --- This, in turn, can happen if the name server is restarted...\n", _local_addr.get_host_addr(), _local_addr.get_port_number()));
	  ACE_DEBUG ((LM_WARNING, "*** --- without first stopping any processes that talked to the old server.\n", _local_addr.get_host_addr(), _local_addr.get_port_number()));
	  return ACE_INVALID_HANDLE;

		// and the thread is not started.
	}
	
	// closes down any still open thread (just in case?).
	if (_initialized) closeAll ();

	_own_name = id.getName();
	_initialized = 1;

	Begin();

	return _acceptor_socket.get_handle ();
}