int YARPGalilDeviceDriver::set_output_bit(void *n)
{
	char *cTmp;
	long rc = 0;
	cTmp = (char *) n;
	int cmd_length = 0;

	char *buff = m_buffer_out;

	///////////////////////////////////////////////////////////////////
	// set output bit
	buff = _append_cmd((char) 0xEA, buff);		//SB
	buff = _append_cmd((char) 0x01, buff);		//01 one byte
	buff = _append_cmd((char) 0x00, buff);

	// axes, don't know why we need 0x01 ! 
	buff = _append_cmd((char) 0x01, buff);

	buff = _append_cmd(*cTmp, buff);	// output value
	
	cmd_length = 5;

	rc = DMCBinaryCommand((HANDLEDMC) m_handle,
							(unsigned char *) m_buffer_out, cmd_length ,
							m_buffer_in, buff_length);
	
	return rc;
}