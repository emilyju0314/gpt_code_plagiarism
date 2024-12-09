int CHexEditDoc::GetBmpInfo(CString &format, CString &bpp, CString &width, CString &height)
{
	// Clear strings in case of error return
	format = "";
	bpp = width = height = "";

	if (pthread6_ == NULL)
		return -4;         // no bitmap preview for this file

	format = "Unknown";

	// Protect access to shared data
	CSingleLock sl(&docdata_, TRUE);

	if (preview_dib_ == NULL)
		return -2;

	ASSERT(preview_fif_ != FREE_IMAGE_FORMAT(-999));
	if (preview_fif_ > FIF_UNKNOWN && preview_fif_ <= FIF_RAW)
	{
		format = CString(format_name[int(preview_fif_)]);
		bpp.Format("%d bits/pixel", preview_bpp_);
		width.Format("%u pixels", preview_width_);
		height.Format("%u pixels", preview_height_);
	}

	return 0;
}