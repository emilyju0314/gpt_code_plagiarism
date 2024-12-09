static void mid_stripoff(MIDTRACK *tp, MIDEVENT *e)
{
#ifndef NEWMIKMOD
	MIDEVENT *ep, *en;
	for( ep=e->next; ep; ep = en ) {
		en=ep->next;
		free(ep);
	}
#endif
	e->next  = NULL;
	tp->tail = e;
	tp->workevent = tp->head;
	mid_sync_track(tp, e->tracktick);
}