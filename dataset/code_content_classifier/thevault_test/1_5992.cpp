int
YARPGalilDeviceDriver::set_dr(void * value)
{
	int rc = 0;
	int * _value = (int *) value;

	char *buff = m_buffer_out;

	buff = _append_cmd("DR",buff);
	buff = _append_cmd(itoa((int)(* _value),m_aux_buffer,10),
					   buff);
	buff = _append_cmd('\0', buff);

	rc = DMCCommand((HANDLEDMC) m_handle,
					m_buffer_out,
					m_buffer_in, 
					buff_length);
	return rc;
}