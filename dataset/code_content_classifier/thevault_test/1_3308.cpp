int CCalcBits::spacing(int bnum)
{
	int retval = 0;
	if (bnum%4 == 0)
		retval += m_nn;
	if (bnum%8 == 0)
		retval += m_bb;
	if (bnum%16 == 0)
		retval += m_cc;
	return retval;
}