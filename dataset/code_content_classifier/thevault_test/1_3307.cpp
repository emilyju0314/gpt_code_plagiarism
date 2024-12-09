BOOL CCalcBits::OnEraseBkgnd(CDC* pDC)
{
	CRect rct;    // used for drawing/fills etc and for calculations
	GetClientRect(&rct);
	pDC->FillSolidRect(rct, afxGlobalData.clrBarFace);
	//pDC->FillRect(&rct, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));

	// Don't show anything if it's not an int
	if (m_pParent->state_ == CALCERROR || m_pParent->state_ >= CALCINTEXPR)
		return TRUE;

	int wndHeight = rct.Height();
	calc_widths(rct);

	COLORREF base_colour =  m_pParent->radix_ == 16 ? ::BestHexAddrCol() :
	                        m_pParent->radix_ == 10 ? ::BestDecAddrCol() :
							                          ::GetSysColor(COLOR_BTNTEXT);
	base_colour = ::same_hue(base_colour, 100, 35);
	COLORREF disabled_colour = ::tone_down(base_colour, ::afxGlobalData.clrBarFace, 0.6);
	COLORREF enabled_colour = ::add_contrast(base_colour,  ::afxGlobalData.clrBarFace);

	// Set up the graphics objects we need for drawing the bits
	//CPen penDisabled(PS_SOLID, 0, ::tone_down(::GetSysColor(COLOR_BTNTEXT), ::afxGlobalData.clrBarFace, 0.7));
	//CPen penEnabled (PS_SOLID, 0, ::GetSysColor(COLOR_BTNTEXT));
	CPen penDisabled(PS_SOLID, 0, disabled_colour);
	CPen penEnabled (PS_SOLID, 0, enabled_colour);

	CFont font;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = 10;
	strcpy(lf.lfFaceName, "Tahoma");  // Simple font for small digits
	font.CreateFontIndirect(&lf);
	CFont *pOldFont = (CFont *)pDC->SelectObject(&font);

	// Start off with disabled colours as we draw from left (disabled side first)
	COLORREF colour = ::tone_down(base_colour, ::afxGlobalData.clrBarFace, 0.8);
	CPen * pOldPen = (CPen*) pDC->SelectObject(&penDisabled);
	bool enabled = false;

	// We need this so Rectangle() does not fill
	CBrush * pOldBrush = pDC->SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));

	// Draw bits from left to right
	int horz = 1;                        // current horizontal position
	// Work out the size of one bit's image and the position of the left (most sig.) bit
	rct.left = horz;
	rct.right = rct.left + m_ww - 1;  // Subtract 1 to leave (at least) one pixel between each bit
	rct.top = 1;
	rct.bottom = rct.top + m_hh;

	unsigned __int64 val;
	// If showing result after binop button pressed then previous_ has the displayed value
	if (m_pParent->state_ == CALCINTBINARY && m_pParent->op_ != binop_none)
		val = mpz_get_ui64(m_pParent->previous_.get_mpz_t());
	else
		val = mpz_get_ui64(m_pParent->current_.get_mpz_t());
	for (int bnum = 63; bnum >= 0; bnum--)
	{
		// When we hit the first enabled bit switch to the darker pen
		if (!enabled && (bnum < m_pParent->bits_ || m_pParent->bits_ == 0))
		{
			pDC->SelectObject(&penEnabled);
			colour = enabled_colour;
			enabled = true;
		}

		if ( (val & ((__int64)1<<bnum)) != 0)
			pDC->FillSolidRect(rct, colour);
		pDC->Rectangle(&rct);

		// Draw numbers underneath some digits
		if (m_hh < wndHeight - 10 && (bnum%8 == 0 || bnum == 63))
		{
			char buf[4];
			sprintf(buf, "%d", bnum);
			pDC->SetTextColor(colour);
			pDC->SetBkColor(afxGlobalData.clrBarFace);
			pDC->TextOut(horz, m_hh + 1, buf, strlen(buf));
		}

		// Move horizontally to next bit position
		horz += m_ww + spacing(bnum);

		rct.MoveToX(horz);
	}
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldFont);

	return TRUE;
}