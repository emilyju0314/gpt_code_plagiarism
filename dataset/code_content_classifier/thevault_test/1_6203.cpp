int YARPOutputSocketMulti::Prepare (const YARPUniqueNameID& name)
{
	OSDataMulti& d = OSDATA(system_resources);
	
	char myhostname[YARP_STRING_LEN];
	getHostname (myhostname, YARP_STRING_LEN);
	d._local_addr.set ((u_short)0, myhostname);
	d._remote_addr = ((YARPUniqueNameSock&)name).getAddressRef();

	identifier = ACE_INVALID_HANDLE;

	return YARP_OK;
}