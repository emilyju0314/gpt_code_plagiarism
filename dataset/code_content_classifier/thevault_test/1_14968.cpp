static void EnableDisableInventoryScrollButtons(void)
{
	if (gubPersonnelInfoState != PRSNL_INV)
	{
		return;
	}

	if (uiCurrentInventoryIndex == 0)
	{
		giPersonnelInventoryButtons[0]->uiFlags &= ~BUTTON_CLICKED_ON;
		DisableButton(giPersonnelInventoryButtons[0]);
	}
	else
	{
		EnableButton(giPersonnelInventoryButtons[0]);
	}


	if ((INT32)uiCurrentInventoryIndex >= (INT32)(GetNumberOfInventoryItemsOnCurrentMerc() - NUMBER_OF_INVENTORY_PERSONNEL))
	{
		giPersonnelInventoryButtons[1]->uiFlags &= ~BUTTON_CLICKED_ON;
		DisableButton(giPersonnelInventoryButtons[1]);
	}
	else
	{
		EnableButton(giPersonnelInventoryButtons[1]);
	}
}