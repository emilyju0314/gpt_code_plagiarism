inline int PAD_BYTES (int len, int pad)
{
	const int rem = len % pad;
	return (rem != 0) ? (pad - rem) : 0;
}