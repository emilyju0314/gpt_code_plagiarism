void CAerialView::draw_pixel(CDC* pDC, int pnum, int x, int y, COLORREF clr1, COLORREF clr2, int horz /*=0*/, int vert)
{
	// Work out which pixel of the ant we are drawing.
	// Note we add ANT_SIZE below as modulus (%) does not behave as expected for -ve numbers.
	int anum = (int(pnum*bfactor_) + ANT_SIZE - timer_count_)%ANT_SIZE;
	if (actual_dpix_ < 7)
	{
		// When zoomed out quickly draw a single pixel
		if (anum < 4)
			pDC->SetPixel(bdr_left_ + x, bdr_top_ + y, clr1);
		else if (anum >= 6 && anum < 10)
			pDC->SetPixel(bdr_left_ + x, bdr_top_ + y, clr2);
		// else we do not drawn anything (transparent)
	}
	else
		for (int ii = 0; ii < actual_dpix_/4; ++ii)
		{
			if (anum < 4)
				pDC->SetPixel(bdr_left_ + x + ii*horz, bdr_top_ + y + ii*vert, clr1);
			else if (anum >= 6 && anum < 10)
				pDC->SetPixel(bdr_left_ + x + ii*horz, bdr_top_ + y + ii*vert, clr2);
			// else we do not drawn anything (transparent)
		}
}