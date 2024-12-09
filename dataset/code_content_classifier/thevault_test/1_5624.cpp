static void abc_synchronise_tracks(ABCHANDLE *h)
{
	ABCTRACK *tp;
	uint32_t tm;	// tracktime in master
	ABCEVENT *em, *es, *et, *ec;	// events in master, slave, slave temporary and copied event
	if( !h || !h->track ) return;
	abc_remove_unnecessary_events(h);
	for( tp = h->track->next; tp; tp = tp->next ) {
		for( em=h->track->head; em; em=em->next ) {
			if( em->flg == 1 ) { // some kind of control event
				switch( em->cmd ) {
					case cmdchord:
					case cmdhide:
					case cmdtempo:
					case cmdsync:
						break;
					default:	// check to see if copy is necessary
						ec = abc_copy_event(h, em);
						tm = em->tracktick;
						es = tp->head; // allways search from the begin...
						for( et=es; et && et->tracktick <= tm; et=et->next )
							es = et;
						if( es == NULL || es->tracktick > tm ) {	// special case: head of track
							ec->next = es;
							tp->head = ec;
						}
						else {
							ec->next = es->next;
							es->next = ec;
						}
						break;
				}
			}
		}
	}
	abc_retick_events(h);
}