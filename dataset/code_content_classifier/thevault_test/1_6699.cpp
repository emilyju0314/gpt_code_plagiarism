void
AckReconsController::recv(Packet *p, Handler *)
{
	Tcl& tcl = Tcl::instance();
	hdr_ip *ip = hdr_ip::access(p);
	tcl.evalf("%s demux %d %d", name(),
		  ip->saddr(), ip->daddr());
	AckRecons *ackRecons = 
		(AckRecons *) TclObject::lookup(tcl.result());
	if (ackRecons == NULL) {
		printf("Error: malformed ack reconstructor\n");
		abort();
	}
	ackRecons->spq_ = spq_;
	ackRecons->recv(p);
}