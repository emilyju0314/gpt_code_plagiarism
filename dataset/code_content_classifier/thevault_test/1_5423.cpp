int	DiscreteFirCustom::compute_real_support () const
{
	const int      len      = int (_coef_arr.size ());
	const int      half_len = (len - 1) / 2;
	int            sup      = half_len + 1;
	for (int pos = 0
	;	   pos < half_len
		&& fstb::is_null (_coef_arr [          pos])
		&& fstb::is_null (_coef_arr [len - 1 - pos])
	;	++pos)
	{
		sup = half_len - pos;
	}

	return (sup);
}