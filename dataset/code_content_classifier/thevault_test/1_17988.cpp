PinoPacket::PinoPacket(char* pPkt, int len)
{
	if (*pPkt++ != VERSION || len < 4) 
	{
		cout << "PinoPacket: unmatched version! " << endl; /* FIXME : Error */
	}

	m_type = *pPkt++;
	pkt_stream = pkt;
	//buildPacket(pkt_type, pkt_body, body_len);
}