double RNG::U01d () 
{ 
	double u; 
	u = U01(); 
	if (anti_) { 
		// Don't forget that U01() returns 1 - u in 
		// the antithetic case 
		u += (U01() - 1.0) * fact; 
		return (u < 0.0) ? u + 1.0 : u; 
	} else { 
		u += U01() * fact; 
		return (u < 1.0) ? u : (u - 1.0); 
	} 
}