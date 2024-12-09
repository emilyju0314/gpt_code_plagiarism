mpz_class CCalcDlg::get_norm(mpz_class v, bool only_pos /*= false*/) const
{
	// If infinite precision (bits_ == 0) then there is no mask
	// Note: this means we can return a -ve value even when signed_ == false
	if (bits_ == 0) return v;

	mpz_class retval = v & mask_;           // mask off high bits

	// If high bit is on then make -ve.
	if (!only_pos && signed_ && mpz_tstbit(v.get_mpz_t(), bits_ - 1))
	{
		// Convert to the 2's complement (invert bits and add one within bits_ range)
		mpz_com(retval.get_mpz_t(), retval.get_mpz_t());
		retval &= mask_;
		++ retval;
		// Now say it is -ve
		mpz_neg(retval.get_mpz_t(), retval.get_mpz_t());
	}

	return retval;
}