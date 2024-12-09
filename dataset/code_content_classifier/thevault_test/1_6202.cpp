int YARPOutputSocketMulti::Close (const YARPUniqueNameID& name)
{
	OSDataMulti& d = OSDATA(system_resources);

	ACE_DEBUG ((LM_DEBUG, "Pretending to close all connections to port %d on %s\n", 
		d._remote_addr.get_port_number(), 
		d._remote_addr.get_host_addr()));

	if (name.getServiceType() != YARP_SHMEM)
	{
		ACE_ASSERT (1 == 0);

		// send the header.
		MyMessageHeader hdr;
		hdr.SetGood ();
		hdr.SetLength (YARP_MAGIC_NUMBER + 1);
		
		ACE_SOCK_Stream stream;
		ACE_Time_Value timeout (YARP_SOCK_TIMEOUT, 0);

		int r = d._service_socket.connect (stream, d._remote_addr, &timeout);
		if (r < 0)
		{
			ACE_DEBUG ((LM_DEBUG, "cannot connect to remote %s:%d\n", d._remote_addr.get_host_addr(), d._remote_addr.get_port_number()));
			identifier = ACE_INVALID_HANDLE;
			return YARP_FAIL;
		}

		stream.send_n (&hdr, sizeof(hdr), 0);

		// wait response.
		hdr.SetBad ();
		r = stream.recv_n (&hdr, sizeof(hdr), 0, &timeout);
		if (r < 0)
		{
			ACE_DEBUG ((LM_DEBUG, "cannot handshake with remote %s:%d\n", d._remote_addr.get_host_addr(), d._remote_addr.get_port_number()));
			identifier = ACE_INVALID_HANDLE;
			stream.close ();
			return YARP_FAIL;
		}

		stream.close ();
	}
	else
	{
		d._stream.close ();
	}

	identifier = ACE_INVALID_HANDLE;

	return YARP_OK;
}