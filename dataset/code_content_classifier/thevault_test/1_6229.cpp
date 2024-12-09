int services::take_ref(const YARPString &name, YARPString &ip, int *type, PORT_LIST &ports)
{
	SVC_IT it(*this);
	if(find_service(name, it) != -1)
	{
		bool ref = true;
		// ref = it->take_ref();	// use ref count
		ip = (*it).ip;
		ports = (*it).ports;
		*type = (*it).type;

		if (ref)
			return 1;	// found, resources avaiable
		else
			return 0;	// found, no more resources
	}
	else
	{
		return -1;		// not found
	}
	
}