static INT32 GetNextButtonNumber(void)
{
	/* Never hand out ID 0.  Slot 0 is always a null pointer */
	for (INT32 x = 1; x < MAX_BUTTONS; x++)
	{
		if (ButtonList[x] == NULL) return x;
	}
	throw std::runtime_error("No more button slots");
}