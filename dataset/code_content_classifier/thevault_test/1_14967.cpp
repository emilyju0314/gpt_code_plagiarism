static void DisplayCharInventory(SOLDIERTYPE const& s)
{
	CreateDestroyPersonnelInventoryScrollButtons();

	BltVideoObject(FRAME_BUFFER, guiPersonnelInventory, 0, STD_SCREEN_X + 397, STD_SCREEN_Y +  200);

	// render the bar for the character
	RenderSliderBarForPersonnelInventory();

	// if this is a robot, don't display any inventory
	if (AM_A_ROBOT(&s)) return;

	INT32 item_count = -(INT32)uiCurrentInventoryIndex;
	for (UINT pos = 0; pos < NUM_INV_SLOTS; ++pos)
	{
		//if the character is a robot, only display the inv for the hand pos
		if (s.ubProfile == ROBOT && pos != HANDPOS) continue; // XXX can this ever be true? before is if (AM_A_ROBOT()) return;

		OBJECTTYPE const& o       = s.inv[pos];
		INT32      const  o_count = o.ubNumberOfObjects;
		if (o_count == 0) continue;

		if (item_count < 0)
		{
			++item_count;
			continue;
		}

		ST::string sString;
		INT16   sX;
		INT16   sY;

		const INT16 PosX = STD_SCREEN_X + 397 + 3;
		const INT16 PosY = STD_SCREEN_Y +  200 + 8 + item_count * 29;

		UINT16  const  item_idx = o.usItem;
		const ItemModel * item = GCM->getItem(item_idx);

		SGPVObject  const& gfx   = GetInterfaceGraphicForItem(item);
		ETRLEObject const& pTrav = gfx.SubregionProperties(item->getGraphicNum());
		INT16       const  cen_x = PosX + ABS(57 - pTrav.usWidth)  / 2 - pTrav.sOffsetX;
		INT16       const  cen_y = PosY + ABS(22 - pTrav.usHeight) / 2 - pTrav.sOffsetY;
		BltVideoObjectOutline(FRAME_BUFFER, &gfx, item->getGraphicNum(), cen_x, cen_y, SGP_TRANSPARENT);

		SetFontDestBuffer(FRAME_BUFFER);

		sString = ItemNames[item_idx];
		sString = ReduceStringLength(sString, 171 - 75, FONT10ARIAL);
		MPrint(PosX + 65, PosY + 3, sString);

		// condition
		if (item->isAmmo())
		{
			INT32 total_ammo = 0;
			for (INT32 i = 0; i < o_count; ++i) total_ammo += o.ubShotsLeft[i];
			sString = ST::format("{}/{}", total_ammo, o_count * item->asAmmo()->capacity);
		}
		else
		{
			sString = ST::format("{2d}%", o.bStatus[0]);
		}

		FindFontRightCoordinates(PosX + 65, PosY + 15, 171 - 75, GetFontHeight(FONT10ARIAL), sString, FONT10ARIAL, &sX, &sY);
		MPrint(sX, sY, sString);

		if (item->isGun())
		{
			sString = *item->asWeapon()->calibre->getName();
			sString = ReduceStringLength(sString, 171 - 75, FONT10ARIAL);
			MPrint(PosX + 65, PosY + 15, sString);
		}

		// if more than 1?
		if (o_count > 1)
		{
			sString = ST::format("x{}", o_count);
			FindFontRightCoordinates(PosX, PosY + 15, 58, GetFontHeight(FONT10ARIAL), sString, FONT10ARIAL, &sX, &sY);
			MPrint(sX, sY, sString);
		}

		if (++item_count == NUMBER_OF_INVENTORY_PERSONNEL) break;
	}
}