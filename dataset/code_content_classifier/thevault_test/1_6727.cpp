double RNG::U01 () 
{ 
	long k; 
	double p1, p2, u; 
	/* Component 1 */ 
	p1 = a12 * Cg_[1] - a13n * Cg_[0]; 
	k = static_cast<long> (p1 / m1); 
	p1 -= k * m1; 
	if (p1 < 0.0) p1 += m1; 
	Cg_[0] = Cg_[1]; Cg_[1] = Cg_[2]; Cg_[2] = p1; 
	/* Component 2 */ 
	p2 = a21 * Cg_[5] - a23n * Cg_[3]; 
	k = static_cast<long> (p2 / m2); 
	p2 -= k * m2; 
	if (p2 < 0.0) p2 += m2; 
	Cg_[3] = Cg_[4]; Cg_[4] = Cg_[5]; Cg_[5] = p2; 
	/* Combination */ 
	u = ((p1 > p2) ? (p1 - p2) * norm : (p1 - p2 + m1) * norm); 
	return (anti_ == false) ? u : (1 - u); 
}