void services::check_in(const YARPString &name, const YARPString &ip, int type, const PORT_LIST &ports, int max_ref)
{
	SVC_IT it(*this);
	if (find_service(name, it) != -1)
	{
		NAME_SERVER_DEBUG(("TCP/UDP/MCAST name %s already registered\n", name.c_str()));
	}
	else
	{
		service tmp;
		tmp.ip = ip;
		tmp.ports = ports;
		tmp.name = name;
		tmp.type = type;
		tmp.set_max_ref(max_ref);
		tmp.take_ref();
		push_back(tmp);
	}
}