static void abc_retick_events(ABCHANDLE *h)
{
	ABCTRACK *tp;
	ABCEVENT *ep;
	uint32_t et, tt=0, at = abcticks(64 * h->speed);
	for( tp=h->track; tp; tp=tp->next ) {
		// make ticks relative
		tt = 0;
		for( ep=tp->head; ep; ep=ep->next ) {
			et = ep->tracktick >> 3;
			ep->tracktick = et - tt;
			tt = et;
		}
		// make ticks absolute again, skipping no-op partbreaks
		tt = 0;
		for( ep=tp->head; ep; ep=ep->next ) {
			ep->tracktick += tt;
			tt = ep->tracktick;
			if( ep->flg == 1 && ep->cmd == cmdpartbrk ) {
				if( tt % at ) {
					tt += at;
					tt /= at;
					tt *= at;
					ep->tracktick -= abcticks(h->speed); // break plays current row
				}
				else ep->cmd = cmdhide;
			}
		}
	}
}