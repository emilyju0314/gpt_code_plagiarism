uint ModuleUI::CreateUI(int num, int x, int y, float scale, int layer, float orderInLayer, bool isDynamic, int lifeFrames, iPoint speed, float cameraSpeed)
{
	//  Get position of the UI
	itemUI* item = new itemUI();
	item->x = x;
	item->y = y;
	item->digitScale = scale;
	item->layer = layer;
	item->orderInLayer = orderInLayer;
	item->isDynamic = isDynamic;
	item->lifeFrames = lifeFrames;
	item->speed = speed;
	item->cameraSpeed = cameraSpeed;

	//Make the number into an array of digits
	//	Declare Variables
	std::stack<int> digits;

	//Getting digits from number in order Logic
	if (num != 0) {
		while (num > 0)
		{
			int digit = num % 10;
			num /= 10;
			digits.push(digit);
		}

		item->totalDigits = digits.size();

		while (!digits.empty())
		{
			int digit = digits.top();
			item->digitVec.push_back(digit);
			digits.pop();
		}
	}
	else
	{
		item->digitVec.push_back(0);
		item->totalDigits = 1;
	}


	for (int i = 0; i < MAX_UI_ITEMS; i++)
	{
		if (uiArray[i] == nullptr)
		{
			uiArray[i] = item;
			return (uint)i;
		}
	}
}