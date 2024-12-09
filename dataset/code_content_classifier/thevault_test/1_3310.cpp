int CCalcBits::pos2bit(CPoint point)
{
	if (point.y <= 0 && point.y >= m_hh - 1)
		return -1;                  // above or below

	// We use an iterative algorithm rather than calculate the bit directly,
	// as it is simpler, more maintainable (re-uses spacing() func as used above)
	// and should be more than fast enough for a user initiated action.
	int horz = 1;
	for (int bnum = 63; bnum >= 0; bnum--)
	{
		if (point.x < horz)
			return -1;              // must be in a gap between two bits
		if (point.x < horz + m_ww - 1)
			return bnum;
		horz += m_ww + spacing(bnum);
	}
	return -1;
}