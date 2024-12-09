unsigned __int64 mpz_get_ui64(mpz_srcptr p)
{
	LARGE_INTEGER val;

	val.LowPart = mpz_getlimbn(p, 0);
	val.HighPart = mpz_getlimbn(p, 1);
	// Any higher limbs are lost - so value is truncated

	if (mpz_sgn(p) < 0)
		return (unsigned __int64)-val.QuadPart;  // ensures correct  (2's complement) bit pattern for -ve values
	else
		return (unsigned __int64)val.QuadPart;
}