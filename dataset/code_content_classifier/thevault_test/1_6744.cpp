int Address::create_ipaddr(int nodeid, int)
{
	return nodeid;
	// The following code is obsolete
#if 0
	int address;
	if (levels_ < 2) 
		address = (nodeid & NodeMask_[1]) << NodeShift_[1];
	else 
		address = nodeid;
	address = ((portid & PortMask_) << PortShift_) | \
		((~(PortMask_) << PortShift_) & address);
	return address;
#endif
}