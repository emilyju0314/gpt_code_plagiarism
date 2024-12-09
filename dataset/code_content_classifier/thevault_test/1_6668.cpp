NsObject* LmsAgent::pkt2agent (Packet *pkt)
{
	Tcl&		tcl = Tcl::instance();
	char		wrk[64];
	const char		*result;
	int		port;
	NsObject*	agent;
	hdr_ip*		ih = HDR_IP(pkt);
	//nsaddr_t	src = ih->saddr();

	port = ih->sport();

	sprintf (wrk, "[%s set node_] agent %d", name (), port);
	tcl.evalc (wrk);
	result = tcl.result ();

#ifdef LMS_DEBUG
printf ("[pkt2agent] port %d, agent %s\n", port, result);
#endif

	agent = (NsObject*)TclObject::lookup (result);
	return (agent);
}