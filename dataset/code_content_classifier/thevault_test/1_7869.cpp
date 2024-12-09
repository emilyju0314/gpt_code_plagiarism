static KFORTH_INTEGER pack32(KFORTH_INTEGER x)
{
	if( x > MAX_INT32 ) {
		return MAX_INT32;

	} else if( x < MIN_INT32 ) {
		return MIN_INT32;

	} else {
		return x;
	}
}