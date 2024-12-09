bool FindUnAssignedLocation(int Grid[GridSize][GridSize], int& Row, int& Col)
{
	for (Row = 0; Row < GridSize; Row++)
	{
		for (Col = 0; Col < GridSize; Col++)
		{
			if (Grid[Row][Col] == UnAssigned)
			{
				return true;
			}
		}
	}
	return false;
}