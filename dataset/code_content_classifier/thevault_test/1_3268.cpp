unsigned __stdcall CHexEditDoc::fi_read(void *buffer, unsigned size, unsigned count, fi_handle handle)
{
	CHexEditDoc *pDoc = (CHexEditDoc *)handle;

	if (pDoc->PreviewProcessStop())
		return 0;       // indicate that processing should stop

	size_t got = pDoc->GetData((unsigned char *)buffer, size*count, pDoc->preview_address_);
	pDoc->preview_address_ += got;
	return got/size;
}