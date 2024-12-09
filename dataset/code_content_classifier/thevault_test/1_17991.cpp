PinoPacket::PinoPacket(char type, PinoComment cmmt) 
{
	list<PinoField> fields;
	string			body;

	if (type != PostCommentReq)
	{
		cout << "PinoPacket: invalid parameter." << endl; /* FIXME: Error! */
	}

	fields = getFieldList(&cmmt);
	if (fields.empty())
	{
		cout << "PinoPacket: invalid parameter." << endl; /* FIXME: Error! */
	}
	m_type = PostCommentReq;
	m_body = buildPacketUnitBody(fields);
	m_len = getPacketUnitBodyLen(m_body);

	/* FIXME:: Allocate memory for ptk_stream, otherwise use C++ string */

	m_stream[0] = VERSION;
	m_stream[1] = PostCommentReq;
	*((unsigned char *) m_stream)	= m_len;
	
	/* TODO: copy m_body to m_stream */
}