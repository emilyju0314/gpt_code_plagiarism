int
YARPGalilDeviceDriver::set_index_search(void * cmd)
{
	bool *tmp = (bool *) cmd;
	_index_search = *tmp; 
	return 0;	
}