void WebTrafPool::pick_ep(TcpAgent** tcp, Agent** snk) {
	// Choose source
	*tcp = picktcp();

	// Choose destination
	if (fulltcp_) {
		*snk = picktcp();
	} else {
		*snk = picksink();
	}
}