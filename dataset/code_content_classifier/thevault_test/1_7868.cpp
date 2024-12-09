static KFORTH_INTEGER pack16(KFORTH_INTEGER x)
{
	if( x > MAX_INT16 ) {
		return MAX_INT16;

	} else if( x < MIN_INT16 ) {
		return MIN_INT16;

	} else {
		return x;
	}
}