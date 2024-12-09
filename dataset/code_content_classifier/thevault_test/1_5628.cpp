static char *abc_continuated(ABCHANDLE *h, MMFILE *mmf, char *p) {
	char *pm, *p1, *p2 = 0;
	int continued;
	pm = p;
	while( pm[strlen(pm)-1]=='\\' ) {
		p1 = strdup(pm);
		if( p2 ) free(p2);
		continued = 1;
		while( continued ) {
			continued = 0;
			pm = abc_gets(h, mmf);
			if( !pm ) {
				abc_message("line not properly continued\n%s", p1);
				return p1;
			}
			while( *pm && isspace(*pm) ) ++pm;
			if( !strncmp(pm,"%%",2) ) {
				for( p2 = pm+2; *p2 && isspace(*p2); p2++ ) ;
				if( !strncmp(p2,"MIDI",4) && (p2[4]=='=' || isspace(p2[4])) ) {
					for( p2+=5; *p2 && isspace(*p2); p2++ ) ;
					if( *p2 == '=' )
						for( p2+=1; *p2 && isspace(*p2); p2++ ) ;
					abc_MIDI_command(h,p2,'%');
				}
				continued = 1;
			}
		}
		p2 = (char *)malloc(strlen(p1)+strlen(pm));
		if( !p2 ) {
			abc_message("macro line too long\n%s", p1);
			return p1;
		}
		p1[strlen(p1)-1] = '\0'; // strip off the backslash
		strcpy(p2,p1);
		strcat(p2,pm);
		pm = p2;
		free(p1);
	}
	return pm;
}