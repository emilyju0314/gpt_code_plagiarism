void TcpAsymAgent::recv_helper(Packet *pkt) 
{
	if (hdr_flags::access(pkt)->ce())
		ecn_to_echo_ = 1;
}