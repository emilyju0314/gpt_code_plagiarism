void SrmNode::handle(Event* event)
{
	SRM_Event *srm_event = (SRM_Event *) event;
	int type  = srm_event->type();
	int seqno = srm_event->seqno();
	//int iif   = srm_event->iif();
	//Scheduler& s = Scheduler::instance();

	switch (type) {
	case SRM_DATA :
		if (seqno != expected_) 
			sched_nack(seqno);
		expected_ = seqno;
		break;

	case SRM_PENDING_RREQ :
		tprintf(("Fired RREQ (node %d)\n", id_));
		remove(seqno, SRM_NO_SUPPRESS);
		srm_event->type(SRM_RREQ);
		break;

	case SRM_RREQ :

		remove(seqno, SRM_SUPPRESS);
		break;

	default :
		tprintf(("panic: node(%d) Unexpected type %d\n", id_, type));
		return;
	}
#ifdef SRM_STAR
	if (type == SRM_RREQ || type == SRM_DATA) {
		delete srm_event;
		return;
	}
#endif
	send(srm_event);	
	return;
}