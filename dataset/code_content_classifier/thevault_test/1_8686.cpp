void open_port( struct glb *g ) {
#ifdef __linux__
	struct serial_params_s *s = &(g->serial_params);
	char *p = g->serial_parameters_string;
	char default_params[] = "115200:8n1";
	int r; 

	if (!p) p = default_params;

	fprintf(stdout,"Attempting to open '%s'\n", s->device);
	s->fd = open( s->device, O_RDWR | O_NOCTTY | O_NDELAY );
	if (s->fd <0) {
		perror( s->device );
	}

	fcntl(s->fd,F_SETFL,0);
	tcgetattr(s->fd,&(s->oldtp)); // save current serial port settings 
	tcgetattr(s->fd,&(s->newtp)); // save current serial port settings in to what will be our new settings
	cfmakeraw(&(s->newtp));

	s->newtp.c_cflag = CS8 |  CLOCAL | CREAD ; 

	if (strncmp(p, "115200:", 7) == 0) s->newtp.c_cflag |= B115200; 
	else if (strncmp(p, "57600:", 6) == 0) s->newtp.c_cflag |= B57600;
	else if (strncmp(p, "38400:", 6) == 0) s->newtp.c_cflag |= B38400;
	else if (strncmp(p, "19200:", 6) == 0) s->newtp.c_cflag |= B19200;
	else if (strncmp(p, "9600:", 5) == 0) s->newtp.c_cflag |= B9600;
	else if (strncmp(p, "4800:", 5) == 0) s->newtp.c_cflag |= B4800;
	else if (strncmp(p, "2400:", 5) == 0) s->newtp.c_cflag |= B2400; //
	else {
		fprintf(stdout,"Invalid serial speed\r\n");
		exit(1);
	}


	s->newtp.c_cc[VMIN] = 0;
	s->newtp.c_cc[VTIME] = g->serial_timeout *10; // VTIME is 1/10th's of second

	p = strchr(p,':');
	if (p) {
		p++;
		switch (*p) {
			case '8': break;
			default: 
						 fprintf(stdout, "Meter only accepts 8 bit mode\n");
		}

		p++;
		switch (*p) {
			case 'o': 
				s->newtp.c_cflag |= PARODD;
				break;
			case 'n': 
				s->newtp.c_cflag &= ~(PARODD|PARENB);
				break;
			case 'e': 
				s->newtp.c_cflag |= PARENB;
				break;
			default: 
				fprintf(stdout, "Parity mode is [n]one, [o]dd, or [e]ven\n");
		}

		p++;
		switch (*p) {
			case '1': 
				s->newtp.c_cflag &= ~CSTOPB;
				break;
			case '2': 
				s->newtp.c_cflag |= CSTOPB;
				break;
			default: 
				fprintf(stdout, "Stop bits are 1, or 2 only\n");
		}

	}

	s->newtp.c_iflag &= ~(IXON | IXOFF | IXANY );

	r = tcsetattr(s->fd, TCSANOW, &(s->newtp));
	if (r) {
		fprintf(stderr,"%s:%d: Error setting terminal (%s)\n", FL, strerror(errno));
		exit(1);
	}

	fprintf(stdout,"Serial port opened, FD[%d]\n", s->fd);
#endif
}