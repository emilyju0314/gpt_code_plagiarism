static BUTTON_PICS* FindFreeButtonSlot(void)
{
	// Search for a slot
	FOR_EACH(BUTTON_PICS, i, ButtonPictures)
	{
		if (i->vobj == NULL) return i;
	}
	throw std::runtime_error("Out of button image slots");
}