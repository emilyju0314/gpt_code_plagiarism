bool joinable(bitmask_t a, bitmask_t b)
{
	return (POPCNT(a ^ b) == 2);
#ifdef __NEVER
	bitmask_t count = 0;

	for (bitmask_t c = a ^ b; c != 0; c = c & (c - 1)) {
		count++;
		if (count > 2)
			return false;
	}
	return (count == 2);
#endif
}