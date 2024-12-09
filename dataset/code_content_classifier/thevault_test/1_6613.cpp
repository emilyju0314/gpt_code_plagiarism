void IvsSource::recv(Packet* pkt, Handler*)
{
	char wrk[128];/*XXX*/
	Tcl& tcl = Tcl::instance();
	hdr_msg *q = hdr_msg::access(pkt);
	sprintf(wrk, "%s handle {%s}", name(), q->msg());
	tcl.eval(wrk);
	Packet::free(pkt);
}