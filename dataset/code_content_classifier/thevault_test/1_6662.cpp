double
OLSR::emf_to_seconds(u_int8_t olsr_format) {
	// This implementation has been taken from unik-olsrd-0.4.5 (mantissa.c),
	// licensed under the GNU Public License (GPL)
	int a = olsr_format >> 4;
	int b = olsr_format - a*16;
	return (double)(OLSR_C*(1+(double)a/16)*(double)pow(2,b));
}