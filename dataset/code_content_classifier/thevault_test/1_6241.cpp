int YARPOutputSocketMcast::Prepare (const YARPUniqueNameID& name)
{
	OSDataMcast& d = OSDATA(system_resources);
	d._mcast_addr = ((YARPUniqueNameSock&)name).getAddressRef();

	YARP_DBG(THIS_DBG) ((LM_DEBUG, "Starting mcast group on port %d and ip %s\n", 
		d._mcast_addr.get_port_number(), 
		d._mcast_addr.get_host_addr()));

	int r = -1;

	if (((YARPUniqueNameSock&)name).getInterfaceName()!=YARPString("default")) {
	  r = d._connector_socket.open (d._mcast_addr, ((YARPUniqueNameSock&)name).getInterfaceName().c_str(), 1);		// reuse addr on, netif = 0.
	} else {
	  r = d._connector_socket.open (d._mcast_addr, NULL, 1);		// reuse addr on, netif = 0.
	}
	if (r == -1)
	{
		ACE_DEBUG ((LM_DEBUG, "cannot open mcast socket %s:%d (%s)\n", d._mcast_addr.get_host_addr(), d._mcast_addr.get_port_number(),
			    ((YARPUniqueNameSock&)name).getInterfaceName().c_str()));
		return YARP_FAIL;
	}

	int ret = YARPNetworkObject::setSocketBufSize (d._connector_socket, MAX_PACKET);
	if (ret != YARP_OK)
	{
		d._connector_socket.close();
		ACE_DEBUG ((LM_DEBUG, "cannot set buffer size to %d\n", MAX_PACKET));
		return YARP_FAIL;
	}

	identifier = d._connector_socket.get_handle ();

	return YARP_OK;
}