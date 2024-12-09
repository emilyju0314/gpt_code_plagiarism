void RNG::reset_start_stream () 
{ 
	for (int i = 0; i < 6; ++i) 
		Cg_[i] = Bg_[i] = Ig_[i]; 
}