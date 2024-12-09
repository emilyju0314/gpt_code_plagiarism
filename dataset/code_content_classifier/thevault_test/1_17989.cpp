PinoPacket::PinoPacket(char type, string url, list <PinoComment> clst)// Query Resp
{
	list<PinoField>		fields;
	list<PinoComment>::iterator it;

	if (type != QueryCommentResp || clst.empty())
	{
		cout << "PinoPacket: Invalid Parameters!" << endl;	/* Error! */
	}
	m_type = QueryCommentResp;
	
	for (it = clst.begin(); it != clst.end(); it++) 
	{
		fields = getFieldList(it); //get fields list of one comment
		if (fields.empty())
			continue;

		m_body += buildPacketUnitBody(fields);
		m_len += getPacketUnitBodyLen(pkt_body);
	}

	/* FIXME:: Allocate memory for ptk_stream, otherwise use C++ string */

	m_stream[0] = VERSION;
	m_stream[1] = QueryCommentResp;
	*((unsigned char *) m_stream)	= m_len;
	
	/* TODO: copy m_body to m_stream. Use C++ style */
}