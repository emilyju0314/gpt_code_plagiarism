int YARPGalilDeviceDriver::read_switches(void *switches)
{
	long rc = 0;
	int cmd_length = 0;
	char *buff = m_buffer_out;
	char *output = (char *) switches;

	///////////////////////////////////////////////////////////////////
	// ST
	buff = _append_cmd((char) 0xDF, buff);		//TS
	buff = _append_cmd((char) 0x00, buff);
	buff = _append_cmd((char) 0x00, buff);
	buff = _append_cmd((char) 0x00, buff);

	cmd_length = 4;

	rc = DMCBinaryCommand((HANDLEDMC) m_handle,
						  (unsigned char *) m_buffer_out, cmd_length ,
						  m_buffer_in, buff_length);

	_ascii_to_binary(m_buffer_in, output);

	return rc;
}