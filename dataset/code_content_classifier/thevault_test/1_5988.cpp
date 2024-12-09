int YARPGalilDeviceDriver::get_ref_speeds(void *spds)
{
	long rc = 0;

	// int *output = (int *) spds;
	double *output = (double *) spds;

	char cmd[] = "SP";
	char *buff = m_buffer_out;

	memcpy(buff, cmd, sizeof(cmd)-1);
	buff+=(sizeof(cmd)-1);

	buff = _append_question_marks(buff);

	// close command
	buff = _append_cmd('\0', buff);

	rc = DMCCommand((HANDLEDMC) m_handle,
					m_buffer_out,
					m_buffer_in, buff_length);

	_ascii_to_binary(m_buffer_in, output);

	return rc;
}