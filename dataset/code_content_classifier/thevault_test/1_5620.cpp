static void	pat_blowup_to16bit(short int *dest, int cbcount) {
	char *s;
	short int *d;
	int t;
	s  = (char *)dest;
	d  = dest;
	s += cbcount;
	d += cbcount;
	for(t=0; t<cbcount; t++)
	{   s--;
			d--;
			*d = (*s) << 8;
	}
}