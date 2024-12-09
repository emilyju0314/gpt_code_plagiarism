void RemoveMercPopupBox(MercPopUpBox* const box)
{
	if (!box) return;

	DeleteVideoSurface(box->uiSourceBufferIndex);

	//DEF Added 5/26
	//Delete the background and the border
	RemoveTextMercPopupImages(box);

	delete box;
}