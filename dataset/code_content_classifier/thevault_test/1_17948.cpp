void ModMousePosition(const int x, const int y, bool bGlobal)
	{
		int newX = GetMouseX() + x;
		int newY = GetMouseY() + y;
		SetMousePosition(newX, newY, bGlobal);
	}