static void DisplayFlowerDynamicItems(void)
{
	UINT32	uiStartLoc=0;
	UINT16	usPosX;
	ST::string sTemp;
	UINT16	usPrice;

	//order number
	usPosX = StringPixLength( sOrderFormText[FLORIST_ORDER_ORDER_NUMBER], FLOWER_ORDEER_SMALL_FONT) + 5 + FLOWER_ORDER_ORDER_NUM_NAME_X;
	sTemp = ST::format("{}", LaptopSaveInfo.uiFlowerOrderNumber);
	DrawTextToScreen(sTemp, usPosX, FLOWER_ORDER_ORDER_NUM_NAME_Y, 0, FLOWER_ORDEER_SMALL_FONT, FLOWER_ORDEER_SMALL_COLOR, FONT_MCOLOR_BLACK, LEFT_JUSTIFIED);

	guiFlowerPrice = 0;
	// the user selected crushed bouquet
	if( gfFLoristCheckBox2Down )
		guiFlowerPrice += gubFlowerOrder_AdditioanalServicePrices[0];

	// the user selected blak roses
	if( gfFLoristCheckBox3Down )
		guiFlowerPrice += gubFlowerOrder_AdditioanalServicePrices[1];

	// the user selected wilted bouquet
	if( gfFLoristCheckBox4Down )
		guiFlowerPrice += gubFlowerOrder_AdditioanalServicePrices[2];

	// the user selected fruit cake
	if( gfFLoristCheckBox5Down )
		guiFlowerPrice += gubFlowerOrder_AdditioanalServicePrices[3];

	//price
	usPosX = StringPixLength( sOrderFormText[FLORIST_ORDER_PRICE], FLOWER_ORDEER_SMALL_FONT) + 5 + FLOWER_ORDER_BOUQUET_NAME_X;
	uiStartLoc = FLOR_GALLERY_TEXT_TOTAL_SIZE * guiCurrentlySelectedFlower + FLOR_GALLERY_TEXT_TITLE_SIZE;
	sTemp = GCM->loadEncryptedString(FLOR_GALLERY_TEXT_FILE, uiStartLoc, FLOR_GALLERY_TEXT_PRICE_SIZE);
	sscanf(sTemp.c_str(), "%hu", &usPrice);

	//if its the next day delivery
	auto destination = GCM->getShippingDestination(gubCurrentlySelectedFlowerLocation);
	if( gfFLoristCheckBox0Down )
		guiFlowerPrice += usPrice + destination->flowersNextDayDeliveryCost;
	//else its the 'when it gets there' delivery
	else
		guiFlowerPrice += usPrice + destination->flowersWhenItGetsThereCost;

	sTemp = ST::format("${}.00 {}", guiFlowerPrice, pMessageStrings[MSG_USDOLLAR_ABBREVIATION]);
	DrawTextToScreen(sTemp, usPosX, FLOWER_ORDER_BOUQUET_NAME_Y, 0, FLOWER_ORDEER_SMALL_FONT, FLOWER_ORDEER_SMALL_COLOR, FONT_MCOLOR_BLACK, LEFT_JUSTIFIED);
}