static void abc_MIDI_beatstring(ABCHANDLE *h, const char *p)
{
	while( isspace(*p) ) p++;
	if( h->beatstring ) _mm_free(h->allochandle, h->beatstring);
	if( strlen(p) )
		h->beatstring = DupStr(h->allochandle,p,strlen(p)+1);
	else
		h->beatstring = NULL;
}