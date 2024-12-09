static int mid_numchans(MIDHANDLE *h)
{
	int i,c,n;
	MIDTRACK *t;
	c = 0;
	for( t = h->track; t; t=t->next )
		c |= (1<<t->chan);
	n = 0;
	for( i=0; i<16; i++ )
		if( c & (1<<i) ) n++;
	return n;
}