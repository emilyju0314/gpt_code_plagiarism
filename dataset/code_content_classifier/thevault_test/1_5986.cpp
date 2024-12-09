int YARPGalilDeviceDriver::abort_axes(void *par)
{
	long rc = 0;

	int cmd_length = 0;

	char *buff = m_buffer_out;

	///////////////////////////////////////////////////////////////////
	// AB
	buff = _append_cmd((char) 0xA2, buff);		//AB
	buff = _append_cmd((char) 0x00, buff);
	buff = _append_cmd((char) 0x00, buff);
	buff = _append_cmd((char) 0x00, buff);

	cmd_length = 4;

	rc = DMCBinaryCommand((HANDLEDMC) m_handle,
						  (unsigned char *) m_buffer_out, cmd_length ,
						  m_buffer_in, buff_length);

	return rc;
}