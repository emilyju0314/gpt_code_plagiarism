double real48(const unsigned char *pp, int *pexp, long double *pmant, bool big_endian /*=false*/)
{
	// Copy bytes containing the real48 in case we have to flip byte order
	unsigned char buf[6];
	memcpy(buf, pp, 6);
	if (big_endian)
		flip_bytes(buf, 6);

	int exponent = (int)buf[0] - 128;
	if (pexp != NULL) *pexp = exponent;

	// Build integer mantissa (without implicit leading bit)
	__int64 mantissa = buf[1] + ((__int64)buf[2]<<8) + ((__int64)buf[3]<<16) +
					((__int64)buf[4]<<24) + ((__int64)(buf[5]&0x7F)<<32);

	// Special check for zero
	if (::memcmp(buf, "\0\0\0\0\0", 5)== 0 && (buf[5] & 0x7F) == 0)
	{
		if (pmant != NULL) *pmant = 0.0;
		return 0.0;
	}

	// Add implicit leading 1 bit
	mantissa +=  (_int64)1<<39;

	if (pmant != NULL)
	{
		if ((buf[5] & 0x80) == 0)
			*pmant = mantissa / (two_pow40 / 2);
		else
			*pmant = -(mantissa / (two_pow40 / 2));
	}

	// Check sign bit and return appropriate result
	if (buf[0] == 0 && mantissa < two_pow40/4)
		return 0.0;                            // underflow
	else if ((buf[5] & 0x80) == 0)
		return (mantissa / two_pow40) * powl(2, exponent);
	else
		return -(mantissa / two_pow40) * powl(2, exponent);
}