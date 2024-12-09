void SrmNode::send(SRM_Event *e) 
{
	/* 
	 * Copy the packet and send it over to 
	 * all the outbound interfaces 
	 */
	int nn;
	Scheduler& s = Scheduler::instance();
	SRM_Event *copy;
	Interface *p;
	Interface_List *ilist = topology->oif(id_, e->iif());
	if (e->iif() < 0)
		e->iif(id_);

	if (ilist) {
		for (p=ilist->head_; p; p=p->next_) {
			nn = p->in_;
			int t = e->type();
			//int i = id_; 
			int snum = e->seqno();
			SrmNode *next = topology->node(nn);
			if (next) {
				copy = new SRM_Event(snum, t, id_);
				s.schedule(next, copy,
					   topology->delay(id_, nn));	 
			}
		}
	}
	delete ilist;
	delete e;
}