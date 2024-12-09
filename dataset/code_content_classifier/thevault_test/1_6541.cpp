void WebTrafPool::launchResp(int obj_id, Node *svr_, Node *clnt_, Agent *tcp, Agent* snk, int size, int pid) {

	// Setup TCP connection and done
	Tcl::instance().evalf("%s launch-resp %d %d %s %s %s %s %d", 
			      name(), obj_id, pid, svr_->name(), clnt_->name(),
			      tcp->name(), snk->name(), size);

	// Debug only
	// $numPacket_ $objectId_ $pageId_ $sessionId_ [$ns_ now] src dst
#if 0
	printf("%d \t %d \t %d \t %d \t %g %d %d\n", size, obj, pg->id(), id_,
	       Scheduler::instance().clock(), 
	       src_->address(), pg->dst()->address());
	printf("** Tcp agents %d, Tcp sinks %d\n", nTcp(),nSink());
#endif
}