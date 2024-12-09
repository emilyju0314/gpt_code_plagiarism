static INT16 FindFreeIconSlot(void)
{
	for (INT16 x = 0; x < MAX_BUTTON_ICONS; ++x)
	{
		if (GenericButtonIcons[x] == NULL) return x;
	}
	throw std::runtime_error("Out of generic button icon slots");
}