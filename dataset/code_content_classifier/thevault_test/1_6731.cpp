double RNG::rand_u01 () 
{ 
	if (inc_prec_) 
		return U01d(); 
	else 
		return U01(); 
}