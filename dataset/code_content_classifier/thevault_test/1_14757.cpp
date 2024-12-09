static void ShutdownButtonImageManager(void)
{
	// Remove all QuickButton images
	FOR_EACH(BUTTON_PICS, i, ButtonPictures)
	{
		if (i->vobj != NULL) UnloadButtonImage(i);
	}

	// Remove all GenericButton images
	if (GenericButtonOffNormal != NULL)
	{
		DeleteVideoObject(GenericButtonOffNormal);
		GenericButtonOffNormal = NULL;
	}

	if (GenericButtonOffHilite != NULL)
	{
		DeleteVideoObject(GenericButtonOffHilite);
		GenericButtonOffHilite = NULL;
	}

	if (GenericButtonOnNormal != NULL)
	{
		DeleteVideoObject(GenericButtonOnNormal);
		GenericButtonOnNormal = NULL;
	}

	if (GenericButtonOnHilite != NULL)
	{
		DeleteVideoObject(GenericButtonOnHilite);
		GenericButtonOnHilite = NULL;
	}

	GenericButtonFillColors = 0;

	// Remove all button icons
	for (int x = 0; x < MAX_BUTTON_ICONS; ++x)
	{
		if (GenericButtonIcons[x] != NULL) UnloadGenericButtonIcon(x);
	}
}