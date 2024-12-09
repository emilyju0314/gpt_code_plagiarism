static UINT bg_func(LPVOID pParam)
{
	CHexEditDoc *pDoc = (CHexEditDoc *)pParam;

	TRACE1("+++ Preview thread started for doc %p\n", pDoc);

	return pDoc->RunPreviewThread();
}