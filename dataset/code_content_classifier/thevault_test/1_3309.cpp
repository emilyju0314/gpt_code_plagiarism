void CCalcBits::calc_widths(CRect & rct)
{
	m_ww = rct.Width()/70;                 // width of display for one bit
	ASSERT(m_ww > 3);
	m_hh = 4 + (rct.Height() - 6)/2;
	if (m_hh < 7)
		m_hh = 7;
	else if (m_hh > 16)
		m_hh = 16;
	if (m_hh > rct.Height() - 1)
		m_hh = rct.Height() - 1;
	m_nn = (rct.Width()-m_ww*64)/22;             // sep between nybbles = half of rest split ~15 ways
	m_bb = (rct.Width()-m_ww*64-m_nn*16)/10;     // sep between bytes = half of rest split ~7 ways
	m_cc = (rct.Width()-m_ww*64-m_nn*16-m_bb*8)/3; // sep between words = rest of space split 3 ways
	ASSERT(m_nn > 0 && m_bb > 0 && m_cc > 0);      // sanity check
}