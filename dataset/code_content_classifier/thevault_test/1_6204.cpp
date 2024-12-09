int YARPOutputSocketMulti::Connect (const YARPUniqueNameID& name, const YARPString& own_name)
{

	OSDataMulti& d = OSDATA(system_resources);
	ACE_Time_Value timeout (YARP_SOCK_TIMEOUT, 0);

	// send the header.
	int port_number = 0;
	MyMessageHeader hdr;
	hdr.SetGood ();
	hdr.SetLength (YARP_MAGIC_NUMBER + 2 + 128*name.getRequireAck());

	// verifies it's a new connection.
	ACE_INET_Addr nm = ((YARPUniqueNameSock&)name).getAddressRef();
	ACE_SOCK_Stream stream;

	int r = d._service_socket.connect (stream, nm, &timeout);
	if (r < 0)
	{
		ACE_DEBUG ((LM_DEBUG, "cannot connect to remote %s:%d\n", nm.get_host_addr(), nm.get_port_number()));
		return YARP_FAIL;
	}

	stream.send_n (&hdr, sizeof(hdr), 0);

	// fine, now send the name of the connection.
	NetInt32 name_len = own_name.length();
	stream.send_n (&name_len, sizeof(NetInt32), 0);
	stream.send_n (own_name.c_str(), name_len, 0);

	// wait response.
	hdr.SetBad ();
	r = stream.recv_n (&hdr, sizeof(hdr), 0, &timeout);
	if (r < 0)
	{
		ACE_DEBUG ((LM_ERROR, "*** error, cannot handshake with remote %s:%d\n", nm.get_host_addr(), nm.get_port_number()));
		stream.close ();
		return YARP_FAIL;
	}

	port_number = hdr.GetLength();
	if (port_number == -1)
	{
		// there might be a real -1 port number -> 65535.
		ACE_DEBUG ((LM_ERROR, "*** error, got garbage back from remote %s:%d\n", d._remote_addr.get_host_addr(), d._remote_addr.get_port_number()));
		stream.close ();
		return YARP_FAIL;
	}

	stream.close ();

	// the connect changes the remote port number to the actual assigned channel.
	// should close on this address.
	d._remote_addr.set_port_number (port_number);

	//d._mem_addr.set(d._local_addr);
	//d._mem_addr.set_port_number(port_number);
	
	d._mem_addr.set (port_number, d._local_addr.get_host_addr());

	// at this point the remote should be listening on port_number

	// Sets the delivery strategy.
	d._connector_socket.preferred_strategy (ACE_MEM_IO::Reactive);

	r = d._connector_socket.connect (d._stream, d._mem_addr);

	if (r == -1)
	{
	  ACE_DEBUG ((LM_ERROR, "*** CHECK that your machine's domain name is configured\n"));
	  ACE_DEBUG ((LM_ERROR, "*** A lack of domain name can make the two sides of a connection seem ...\n"));
	  ACE_DEBUG ((LM_ERROR, "*** ... to be on different machines, and prevent shared memory from kicking in\n"));
	  ACE_DEBUG ((LM_DEBUG, "cannot connect shmem socket %s:%d, error code is %d\n", d._mem_addr.get_host_addr(), d._mem_addr.get_port_number(),r));

	  identifier = ACE_INVALID_HANDLE;
		return YARP_FAIL;
	}

	identifier = d._stream.get_handle ();

	return YARP_OK;
}