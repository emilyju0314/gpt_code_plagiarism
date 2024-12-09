int
YARPGalilDeviceDriver::find_index()
{
	int rc = 0;
	char *buff = m_buffer_out;

	buff = _append_cmd((char) 0xA5, buff);		//FI
	buff = _append_cmd((char) 0x00, buff);		//00 no data fields
	buff = _append_cmd((char) 0x00, buff);		//00 no coordinated movement
	buff = _append_cmd((char) 0x00, buff);		//00 for all the axis

	rc = DMCBinaryCommand((HANDLEDMC) m_handle,
						  (unsigned char *) m_buffer_out, 
						  4,
						  m_buffer_in, 
						  buff_length);
	return rc;
}