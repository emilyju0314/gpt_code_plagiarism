void SrmNode::sched_nack(int seqno) 
{
	double backoff;
	Scheduler& s = Scheduler::instance();
	SRM_Event *event = new SRM_Event(seqno, 
					 SRM_PENDING_RREQ, SRM_NOIF);
	append(event);

	backoff = topology->backoff(id_);
//	tprintf(("node(%d) schd rrq after %f s\n", id_, backoff));
	s.schedule(this, event, backoff);
}