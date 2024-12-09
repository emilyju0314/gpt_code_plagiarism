static BOOLEAN ValidAttachmentClass(UINT16 usAttachment, UINT16 usItem)
{
	for (auto const& ai : AttachmentInfo)
	{
		// see comment for AttachmentInfo array for why we skip IC_NONE
		if (ai.uiItemClass == IC_NONE) continue;

		if (ai.usItem == usAttachment && ai.uiItemClass == GCM->getItem(usItem)->getItemClass())
		{
			return TRUE;
		}
	}
	return FALSE;
}