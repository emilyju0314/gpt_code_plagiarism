CFOR_EACH_WORLD_ITEM(wi)
	{
		OBJECTTYPE const& o = wi.o;
		if (o.usItem == MONEY) uiTotalCash += o.uiMoneyAmount;
	}