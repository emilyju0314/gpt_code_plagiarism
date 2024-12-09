void WebTrafPool::launchReq(Node *src_, void* ClntData, int obj, int size) {
	TcpAgent *ctcp;
	Agent *csnk;

	// Allocation new TCP connections for both directions
	pick_ep(&ctcp, &csnk);

	WebPage* pg = (WebPage*)ClntData;
	pages_[pg->id()] = ClntData;

	// Setup TCP connection and done
	Tcl::instance().evalf("%s launch-req %d %d %s %s %s %s %d", 
			      name(), obj, pg->id(),
			      src_->name(), pg->dst()->name(),
			      ctcp->name(), csnk->name(), size);

	// Debug only
	// $numPacket_ $objectId_ $pageId_ $sessionId_ [$ns_ now] src dst
#if 0
	printf("%d \t %d \t %d \t %d \t %g %d %d\n", size, obj, pg->id(), id_,
	       Scheduler::instance().clock(), 
	       src_->address(), pg->dst()->address());
	printf("** Tcp agents %d, Tcp sinks %d\n", nTcp(),nSink());
#endif
}