int YARPGalilDeviceDriver::check_motion_done2 (void *flag)
{
	long rc = 0;
	rc = read_switches (m_buffer_in);
	bool _moving = false;
	int i;
	for(i = 0; i < m_njoints; i++)
		_moving = _moving || ((char) 0x80 & m_buffer_in[i]);

	*(bool *)flag = _moving;
	return rc;
}