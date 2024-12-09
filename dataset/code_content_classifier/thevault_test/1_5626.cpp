static void abc_MIDI_beat(ABCHANDLE *h, const char *p)
{
	int i,j;
	h->beat[0] = 127;
	h->beat[1] = 125;
	h->beat[2] = 110;
	h->beat[3] = 1;
	for( j=0; j<4; j++ ) {
		while( isspace(*p) ) p++;
		if( *p ) {
			p += abc_getnumber(p, &i);
			if( i < 0   ) i = 0;
			if( i > 127 ) i = 127;
			h->beat[j] = i;
		}
	}
	if( h->beat[3] == 0 ) h->beat[3] = 1; // BB Ruud says: do not let you make mad
}