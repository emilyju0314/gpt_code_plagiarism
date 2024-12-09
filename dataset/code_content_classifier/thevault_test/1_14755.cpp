static void InitializeButtonImageManager(void)
{
	// Blank out all QuickButton images
	for (int x = 0; x < MAX_BUTTON_PICS; ++x)
	{
		BUTTON_PICS* const pics = &ButtonPictures[x];
		pics->vobj      = NULL;
		pics->Grayed    = -1;
		pics->OffNormal = -1;
		pics->OffHilite = -1;
		pics->OnNormal  = -1;
		pics->OnHilite  = -1;
	}

	// Blank out all Generic button data
	GenericButtonOffNormal  = NULL;
	GenericButtonOffHilite  = NULL;
	GenericButtonOnNormal   = NULL;
	GenericButtonOnHilite   = NULL;
	GenericButtonFillColors = 0;

	// Blank out all icon images
	for (int x = 0; x < MAX_BUTTON_ICONS; ++x)
		GenericButtonIcons[x] = NULL;

	// Load the default generic button images
	GenericButtonOffNormal = AddVideoObjectFromFile(DEFAULT_GENERIC_BUTTON_OFF);
	GenericButtonOnNormal  = AddVideoObjectFromFile(DEFAULT_GENERIC_BUTTON_ON);

	/* Load up the off hilite and on hilite images. We won't check for errors
	 * because if the file doesn't exists, the system simply ignores that file.
	 * These are only here as extra images, they aren't required for operation
	 * (only OFF Normal and ON Normal are required).
	 */
	try
	{
		GenericButtonOffHilite = AddVideoObjectFromFile(DEFAULT_GENERIC_BUTTON_OFF_HI);
	}
	catch (...) { /* see comment above */ }
	try
	{
		GenericButtonOnHilite  = AddVideoObjectFromFile(DEFAULT_GENERIC_BUTTON_ON_HI);
	}
	catch (...) { /* see comment above */ }

	UINT8 const Pix = GenericButtonOffNormal->GetETRLEPixelValue(8, 0, 0);
	GenericButtonFillColors = GenericButtonOffNormal->Palette16()[Pix];
}