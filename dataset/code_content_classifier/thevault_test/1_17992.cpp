PinoPacket::PinoPacket(char type, string url)
{
	string  pkt_body = "";
	unsigned char body_type;
	int	body_len = 0;
     string body_val;
	list<PinoField> fields;
    
	if (type != QueryCommentReq || url.empty())
	{
		cout << "Packet type does not match!" << endl; /* FIXME: Error! */
	}    

	fields.push_back(PinoField(FIELD_TYPE_URL, url.length, url));

        m_type = QueryCommentReq;
	m_body = buildPacketUnitBody(fields);
	m_len = getPacketUnitBodyLen(pkt_body);

	/* FIXME:: Allocate memory for ptk_stream, otherwise use C++ string */

	m_stream[0] = VERSION;
	m_stream[1] = QueryCommentReq;
	*((unsigned char *) m_stream)	= m_len;
	
	/* TODO: copy m_body to m_stream. Use C++ style */
}