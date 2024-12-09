void CHexEditView::draw_adjusters(CDC* pDC)
{
	int xpos;

	// Set up pen and brush colours (all adjusters are the same colour)
	CPen pen(PS_SOLID, 0, RGB(0,0,0));          // black pen
	CPen pdash(PS_DOT, 0, RGB(0,0,0));          // for dashed black line
	CBrush bwhite(RGB(255,255,255));            // white brush
	CBrush bred(RGB(192,0,0));                  // red brush
	CPen * psp = pDC->SelectObject(&pen);       // ptr to saved pen
	CBrush * psb = pDC->SelectObject(&bwhite);  // ptr to saved brush

	// Show rowsize_ in the ruler
	ASSERT(rowsize_ > 3);
	if (!display_.vert_display && display_.hex_area)
	{
		if (adjusting_rowsize_ == -1 || adjusting_rowsize_ == rowsize_)
			xpos = char_pos(0) - text_width_w_/2 - scrollpos_.x;
		else
			xpos = hex_pos(adjusting_rowsize_) - scrollpos_.x;
		if (display_.autofit)
			pDC->SelectObject(&bred);
		draw_rowsize(pDC, xpos-1);
		if (display_.autofit)
			pDC->SelectObject(&bwhite);
		if (adjusting_rowsize_ > -1)
		{
			(void)pDC->SelectObject(pdash);
			pDC->MoveTo(xpos-1, bdr_top_);
			pDC->LineTo(xpos-1, 30000);
			(void)pDC->SelectObject(pen);
		}
	}
	else if (display_.vert_display || display_.char_area)
	{
		if (adjusting_rowsize_ == -1 || adjusting_rowsize_ == rowsize_)
			xpos = char_pos(rowsize_ - 1) + (3*text_width_w_)/2 - scrollpos_.x;
		else
			xpos = char_pos(adjusting_rowsize_) - scrollpos_.x;
		if (display_.autofit)
			pDC->SelectObject(&bred);
		draw_rowsize(pDC, xpos-1);
		if (display_.autofit)
			pDC->SelectObject(&bwhite);
		if (adjusting_rowsize_ > -1)
		{
			(void)pDC->SelectObject(pdash);
			pDC->MoveTo(xpos-1, bdr_top_);
			pDC->LineTo(xpos-1, 30000);
			(void)pDC->SelectObject(pen);
		}
	}

	// Show position of "offset_" in the ruler (in hex and/or char areas)
	ASSERT(offset_ < rowsize_);
	if (!display_.vert_display && display_.hex_area)
	{
		if (adjusting_offset_ > -1)
			xpos = hex_pos(rowsize_ - (rowsize_ + adjusting_offset_ - 1) % rowsize_ - 1) - 
			       scrollpos_.x;
		else
			xpos = hex_pos(offset_) - scrollpos_.x;
		draw_offset(pDC, xpos-1);
		if (adjusting_offset_ > -1)
		{
			(void)pDC->SelectObject(pdash);
			pDC->MoveTo(xpos-1, bdr_top_);
			pDC->LineTo(xpos-1, 30000);
			(void)pDC->SelectObject(pen);
		}
	}
	if (display_.vert_display || display_.char_area)
	{
		if (adjusting_offset_ > -1)
			xpos = char_pos(rowsize_ - (rowsize_ + adjusting_offset_ - 1) % rowsize_ - 1) -
			       scrollpos_.x;
		else
			xpos = char_pos(offset_) - scrollpos_.x;
		if (display_.vert_display || !display_.hex_area)
			draw_offset(pDC, xpos-1);
		if (adjusting_offset_ > -1)
		{
			(void)pDC->SelectObject(pdash);
			pDC->MoveTo(xpos-1, bdr_top_);
			pDC->LineTo(xpos-1, 30000);
			(void)pDC->SelectObject(pen);
		}
	}

	// Show current grouping if not adjusting (adjusting_group_by_ == -1) OR
	// current adjust column if not dragged past the edge (adjusting_group_by_ < 9999)
	if (adjusting_group_by_ == -1 && group_by_ < rowsize_ ||
		adjusting_group_by_ > -1 && adjusting_group_by_ < rowsize_)
	{
		if (display_.vert_display)
		{
			if (adjusting_group_by_ > -1)
				xpos = char_pos(adjusting_group_by_) - scrollpos_.x;
			else
				xpos = char_pos(group_by_) - scrollpos_.x;
			if (display_.vert_display && 
				(adjusting_group_by_ == -1 || adjusting_group_by_%group_by_ == 0))
				xpos -= text_width_w_/2;
			draw_group_by(pDC, xpos);
			if (adjusting_group_by_ > -1)
			{
				// Draw vertical dashed line
				(void)pDC->SelectObject(pdash);
				pDC->MoveTo(xpos, bdr_top_);
				pDC->LineTo(xpos, 30000);
				(void)pDC->SelectObject(pen);
			}
		}
		else if (display_.hex_area)
		{
			if (adjusting_group_by_ > -1)
				xpos = hex_pos(adjusting_group_by_) - 2 - scrollpos_.x;
			else
				xpos = hex_pos(group_by_) - 2 - scrollpos_.x;
			if (adjusting_group_by_ == -1 || adjusting_group_by_%group_by_ == 0)
				xpos -= (text_width_ - 1);
			draw_group_by(pDC, xpos);
			if (adjusting_group_by_ > -1)
			{
				(void)pDC->SelectObject(pdash);
				pDC->MoveTo(xpos, bdr_top_);
				pDC->LineTo(xpos, 30000);
				(void)pDC->SelectObject(pen);
			}
		}
	}

	(void)pDC->SelectObject(psp);
	(void)pDC->SelectObject(psb);
}