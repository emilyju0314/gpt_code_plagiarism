UINT CHexEditDoc::RunPreviewThread()
{
	// Keep looping until we are told to die
	for (;;)
	{
		// Signal that we are waiting then wait for start_preview_event_ to be pulsed
		{
			CSingleLock sl(&docdata_, TRUE);
			preview_state_ = WAITING;
		}
		TRACE1("+++ BGPreview: waiting for %p\n", this);
		DWORD wait_status = ::WaitForSingleObject(HANDLE(start_preview_event_), INFINITE);
		docdata_.Lock();
		preview_state_ = SCANNING;
		docdata_.Unlock();
		start_preview_event_.ResetEvent();
		ASSERT(wait_status == WAIT_OBJECT_0);
		TRACE1("+++ BGPreview: got event for %p\n", this);

		if (PreviewProcessStop())
			continue;

		// Reset for new scan
		docdata_.Lock();
		preview_fin_ = false;
		preview_address_ = 0;
		if (preview_dib_ != NULL)
		{
			FreeImage_Unload(preview_dib_);
			preview_dib_ = NULL;
		}
		docdata_.Unlock();

		FREE_IMAGE_FORMAT fif = FreeImage_GetFileTypeFromHandle(&fi_funcs, this);
		FIBITMAP * dib;
		// Catch FreeImage_Load exceptions since it has been known to have memory access violations on bad data
		try
		{
			dib = FreeImage_LoadFromHandle(fif, &fi_funcs, this);
		}
		catch (...)
		{
			dib = NULL;
		}
		int bpp = FreeImage_GetBPP(dib);
		unsigned width = FreeImage_GetWidth(dib);
		unsigned height = FreeImage_GetHeight(dib);

		TRACE1("+++ BGPreview: finished load for %p\n", this);
		docdata_.Lock();
		preview_fin_ = true;
		preview_address_ = 0;
		preview_dib_ = dib;

		// Save info about the bitmap just loaded
		preview_fif_ = fif;
		preview_bpp_ = bpp;
		preview_width_ = width;
		preview_height_ = height;
		docdata_.Unlock();
	}
	return 0;   // never reached
}