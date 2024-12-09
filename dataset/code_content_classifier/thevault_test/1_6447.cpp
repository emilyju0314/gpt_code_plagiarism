int
VegasTcpAgent::vegas_expire(Packet* pkt)
{
	hdr_tcp *tcph = hdr_tcp::access(pkt);
	double elapse = vegastime() - v_sendtime_[(tcph->seqno()+1)%v_maxwnd_];
	if (elapse >= v_timeout_) {
		return(tcph->seqno()+1);
	}
	return(-1);
}