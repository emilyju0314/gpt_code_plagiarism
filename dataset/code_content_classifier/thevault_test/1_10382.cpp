void checkExists(vector<vector<vector<int>>> &playerHands, int i, int suit, int card, bool &passCard)
{
	//Checks through the playerHands vector to make sure the certain card is there
	for(int q = 0; q < playerHands[i][suit - 1].size(); q++)
	{
		if(playerHands[i][suit - 1][q] == card - 1)
		{
			passCard = true;
			break;
		}
		else
			passCard = false;
	}
}