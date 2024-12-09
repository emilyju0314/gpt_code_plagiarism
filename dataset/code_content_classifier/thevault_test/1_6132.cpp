int porter (void *params)
{
	_dispatchParams& par = *(_dispatchParams *)params;
	if (par._portname == NULL || 
		par._extra_content == NULL)
		return -1;

	YARPPort::Connect (par._portname, par._extra_content);

	return 0;
}