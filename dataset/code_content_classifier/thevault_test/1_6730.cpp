void RNG::reset_start_substream () 
{ 
	for (int i = 0; i < 6; ++i) 
		Cg_[i] = Bg_[i]; 
}