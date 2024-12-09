void print(std::string secret, int wrong_guesses, const Engine *game)
{
	int len = secret.length();
	std::string andy;
	
	cout << "Press Enter to continue! ";
	cin.ignore();
	system("cls");
	
	// first run
	if (fills == "")
	{
		andy = game->Sprite(0);
		cout << andy;
		
		for (int i = 0; i < len; i++) fills += "_";
	}
	
	else 
	{
		andy = game->Sprite(wrong_guesses);
		cout << andy;
	}
	
	std::cout << "\n\n\tWORD: ";
	for (int i = 0; i < len; i++)
		std::cout << fills[i] << " ";
	std::cout << "\n\n";
}