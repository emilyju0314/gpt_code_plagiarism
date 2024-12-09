bool noise_filt(uint16_t c, uint16_t p)
{
	// threshold parameters
	// set here for easy editing
	const uint16_t t0 = 65000,t1=t0+350;
	// if neither of the pixels are within the activity threshold
	// ignore them
	if((c<=t1)||(p<=t1)){
		return false;
	}
	else{	// then return true for any difference
		return c!=p? true: false;
	}
}