int YARPOutputSocketMcast::Close (const YARPUniqueNameID& name)
{
	OSDataMcast& d = OSDATA(system_resources);

	// send the header.
	MyMessageHeader hdr;
	hdr.SetGood ();
	hdr.SetLength (YARP_MAGIC_NUMBER + 1);

	int i;
	int j = -1;
	//const char *sname = ((YARPUniqueNameSock&)name).getName().c_str();
	ACE_INET_Addr& nm = ((YARPUniqueNameSock &)name).getAddressRef();

	for (i = 0; i < d._max_num_clients; i++)
	{
		//if (d._client_names[i].compare(sname) == 0)
		if (d._client_names[i] == ((YARPUniqueNameSock&)name).getName())
		{
			j = i;
			//ACE_OS::printf("Returned true\n");
			break;
		}
	}

	if (j == -1)
	{
		ACE_DEBUG ((LM_DEBUG, "the specific name is not connected %s:%d\n", nm.get_host_addr(), nm.get_port_number()));
		return YARP_FAIL;
	}

	ACE_SOCK_Stream stream;
	ACE_Time_Value timeout (YARP_SOCK_TIMEOUT, 0);

	int r = d._service_socket.connect (stream, d._clients[j], &timeout);

	if (r < 0)
	{
		ACE_DEBUG ((LM_DEBUG, "cannot connect to %s:%d\n", nm.get_host_addr(), nm.get_port_number()));

		d._clients[j].set ((u_short)0, INADDR_ANY);
		d._client_names[j].clear(1);
	
		d._num_connected_clients --;

		// closes down the socket.
		if (d._num_connected_clients <= 0)
		{
			d._connector_socket.close ();
			identifier = ACE_INVALID_HANDLE;
		}

		return YARP_FAIL;
	}

	stream.send_n (&hdr, sizeof(hdr), 0);

	// wait response.
	hdr.SetBad ();
	r = stream.recv_n (&hdr, sizeof(hdr), 0, &timeout);

	if (r < 0)
	{
		ACE_DEBUG ((LM_DEBUG, "cannot handshake with remote %s:%d\n", d._clients[j].get_host_addr(), d._clients[j].get_port_number()));

		d._clients[j].set ((u_short)0, INADDR_ANY);
		d._client_names[j].clear(1);

		stream.close ();
		d._num_connected_clients --;

		// closes down the socket.
		if (d._num_connected_clients <= 0)
		{
			d._connector_socket.close ();
			identifier = ACE_INVALID_HANDLE;
		}

		return YARP_FAIL;
	}

	d._clients[j].set ((u_short)0, INADDR_ANY);
	d._client_names[j].clear(1);

	stream.close ();
	d._num_connected_clients --;

	// closes down the socket.
	if (d._num_connected_clients <= 0)
	{
		d._connector_socket.close ();
		identifier = ACE_INVALID_HANDLE;
	}

	return YARP_OK;
}