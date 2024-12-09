void CAerialView::draw_bitmap(CDC* pDC)
{
	CHexEditDoc *pDoc = GetDocument();
	ASSERT(pDoc != NULL && pDoc->dib_ != NULL);
	if (pDoc == NULL || pDoc->dib_ == NULL)
		return;

	BITMAPINFOHEADER *bih = FreeImage_GetInfoHeader(pDoc->dib_);
	ASSERT(bih->biCompression == BI_RGB && bih->biHeight > 0);

	// Work out how to "reshape" the bitmap based cols_ (already calced from width of the window and dpix)
	// Note: changing the bitmap header (ie width/height) should only be done just before BLTing
	// the bitmap as more than one view can use the same bitmap and they may require different "shapes".
	bih->biWidth = cols_;
	ASSERT(cols_ % 8 == 0 && cols_ > 0 && cols_ <= CHexEditDoc::MAX_WIDTH);
	ASSERT((pDoc->length_-1)/bih->biWidth < LONG_MAX);
	bih->biHeight = LONG((pDoc->NumElts()-1)/bih->biWidth) + 1;

	int pos = int(scrollpos_/(GetDocument()->GetBpe() * cols_));    // no of rows above top of window
	CRect cliprct; pDC->GetClipBox(&cliprct);                       // only BLT the area that needs it

	// Work out src rect
	int sl = (cliprct.left - bdr_left_)/actual_dpix_;
	if (sl < 0) sl = 0;
	int st = pos + (cliprct.top - bdr_top_)/actual_dpix_;
	if (st < 0) st = 0;
	int sr = (cliprct.right - bdr_left_ - 1)/actual_dpix_ + 1;
	if (sr > bih->biWidth) sr = bih->biWidth;
	int sb = pos + (cliprct.bottom - bdr_top_ - 1)/actual_dpix_ + 1;
	if (sb > bih->biHeight) sb = bih->biHeight;

	// Work out dest rect
	int dl = bdr_left_ + sl*actual_dpix_;
	int dt = bdr_top_ + (st - pos)*actual_dpix_;
	int dr = bdr_left_ + sr*actual_dpix_;
	int db = bdr_top_ + (sb - pos)*actual_dpix_;

	::StretchDIBits(pDC->GetSafeHdc(),
					dl, dt, dr - dl, db - dt,
					sl, sb + 1, sr - sl, st - sb,
					FreeImage_GetBits(pDoc->dib_), FreeImage_GetInfo(pDoc->dib_),
					DIB_RGB_COLORS, SRCCOPY);
}