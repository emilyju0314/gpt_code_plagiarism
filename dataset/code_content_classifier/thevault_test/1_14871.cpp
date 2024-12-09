void SetExternVOData(UINT32 uiCursorIndex, HVOBJECT hVObject, UINT16 usSubIndex)
{
	CursorData* pCurData = &gpCursorDatabase[uiCursorIndex];

	for (UINT32 cnt = 0; cnt < pCurData->usNumComposites; cnt++)
	{
		CursorImage*    pCurImage = &pCurData->Composites[cnt];
		CursorFileData* CFData    = &gpCursorFileDatabase[pCurImage->uiFileIndex];

		if (CFData->Filename == NULL)
		{
			// OK, set Video Object here....

			// If loaded, unload...
			UnLoadCursorData(uiCursorIndex);

			// Set extern vo
			CFData->hVObject      = hVObject;
			pCurImage->uiSubIndex = usSubIndex;

			// Reload....
			LoadCursorData(uiCursorIndex);
		}
	}
}