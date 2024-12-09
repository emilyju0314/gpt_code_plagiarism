int 
YARPGalilDeviceDriver::set_safe_jogs (void *spds) 
{
	long rc = 0;
	// TODO: Implement adequate save jogs in the galil
	
	set_jogs(spds);
	
	return rc;
}