int YARPOutputSocketMcast::Connect (const YARPUniqueNameID& name, const YARPString& own_name)
{
	OSDataMcast& d = OSDATA(system_resources);

	// verifies it's a new connection.
	ACE_INET_Addr nm = ((YARPUniqueNameSock&)name).getAddressRef();

	int i, firstempty = -1;
	for (i = 0; i < d._max_num_clients; i++)
	{
		// don't compare the IP addr because the remote might have already unregistered
		// in that case, name doesn't contain the IP of the remote.

		//if (d._client_names[i].compare(sname) == 0)
		if (d._client_names[i] == ((YARPUniqueNameSock&)name).getName())
		{
			// it's already there...
			ACE_DEBUG ((LM_ERROR, "the specific client is already connected %s:%d\n", d._clients[i].get_host_addr(), d._clients[i].get_port_number()));
			//d._service_socket.close();
			return YARP_FAIL;
		}

		if (d._clients[i].get_port_number() == 0 && firstempty < 0)
		{
			firstempty = i;	
		}
	}

	// send the header.
	int port_number = 0;
	MyMessageHeader hdr;
	hdr.SetGood ();
	hdr.SetLength (YARP_MAGIC_NUMBER + 1 + 128*name.getRequireAck());

	char myhostname[YARP_STRING_LEN];
	getHostname (myhostname, YARP_STRING_LEN);
	ACE_INET_Addr local ((u_short)0, myhostname);
	ACE_SOCK_Stream stream;
	ACE_Time_Value timeout (YARP_SOCK_TIMEOUT, 0);

	int r = d._service_socket.connect (stream, nm, &timeout);
	if (r < 0)
	{
		ACE_DEBUG ((LM_ERROR, "cannot connect to remote service\n"));
		return YARP_FAIL;
	}

	// ask for a connection.
	stream.send_n (&hdr, sizeof(hdr), 0);

	// fine, now send the name of the connection.
	NetInt32 name_len = own_name.length();
	stream.send_n (&name_len, sizeof(NetInt32), 0);
	stream.send_n (own_name.c_str(), name_len, 0);

	// send mcast ip and port #.
	// exactly 6 bytes.
	char buf[6];
	int ip = d._mcast_addr.get_ip_address();
	buf[0] = (ip & 0xff000000) >> 24;
	buf[1] = (ip & 0x00ff0000) >> 16;
	buf[2] = (ip & 0x0000ff00) >> 8;
	buf[3] = (ip & 0x000000ff);
	short portn = d._mcast_addr.get_port_number();
	buf[4] = (portn & 0xff00) >> 8;
	buf[5] = (portn & 0x00ff);
	stream.send_n (buf, 6, 0);
	YARP_DBG(THIS_DBG) ((LM_DEBUG, "supposedly sent %s:%d\n", d._mcast_addr.get_host_addr(), d._mcast_addr.get_port_number()));

	// wait response.
	hdr.SetBad ();
	r = stream.recv_n (&hdr, sizeof(hdr), 0, &timeout);

	if (r < 0)
	{
		stream.close ();
		ACE_DEBUG ((LM_ERROR, "cannot handshake with remote %s:%d\n", nm.get_host_addr(), nm.get_port_number()));
		return YARP_FAIL;
	}

	d._clients[firstempty] = nm;

	port_number = hdr.GetLength();
	if (port_number == -1)
	{
		d._clients[firstempty].set ((u_short)0, INADDR_ANY);
		//d._client_names[firstempty].erase(d._client_names[firstempty].begin(), d._client_names[firstempty].end());
		d._client_names[firstempty].clear(1);

		// there might be a real -1 port number -> 65535.
		stream.close ();
		ACE_DEBUG ((LM_ERROR, "got garbage back from remote %s:%d\n", nm.get_host_addr(), nm.get_port_number()));
		return YARP_FAIL;
	}

	// the connect changes the remote port number to the actual assigned channel.
	d._clients[firstempty].set_port_number (port_number);

	// stores also the full symbolic name as index.
	// this can be changed into a string copy since the name now contains a string.
	d._client_names[firstempty] = ((YARPUniqueNameSock&)name).getName();

	stream.close ();
	d._num_connected_clients ++;

	return YARP_OK;
}