int YARPGalilDeviceDriver::check_motion_done(void *flag)
{
	long rc = 0;

	bool *tmp = (bool *)flag;
	*tmp = true;
	bool subflag = false;

	for (int i = 0; i < m_njoints; i++)
	{
		rc = check_motion_done(&subflag,i);
		*tmp = *tmp && subflag;
	}

	return rc;
/*

	long rc = 0;

	bool *tmp = (bool *) flag;
	
	char cmd[] = "MG _BGABCDEFGH";
	char *buff = m_buffer_out;

	memcpy(buff, cmd, sizeof(cmd)-1);
	buff+=(sizeof(cmd)-1);

	// close command
	buff = _append_cmd('\0', buff);
	
	rc = DMCCommand((HANDLEDMC) m_handle,
					m_buffer_out,
					m_buffer_in, buff_length);

	if (atoi(m_buffer_in))
		*tmp = false;
	else	*tmp = true;
	//_ascii_to_binary(m_buffer_in, tmp);

	return rc;

*/
}