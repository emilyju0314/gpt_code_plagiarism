u_int8_t
OLSR::seconds_to_emf(double seconds) {
	// This implementation has been taken from unik-olsrd-0.4.5 (mantissa.c),
	// licensed under the GNU Public License (GPL)
	
	int a, b = 0;
 	while (seconds/OLSR_C >= pow((double)2, (double)b))
		b++;
	b--;
	
	if (b < 0) {
		a = 1;
		b = 0;
	}
	else if (b > 15) {
		a = 15;
		b = 15;
	}
	else {
		a = (int)(16*((double)seconds/(OLSR_C*(double)pow(2, b))-1));
		while (a >= 16) {
			a -= 16;
			b++;
		}
	}
	
	return (u_int8_t)(a*16+b);
}