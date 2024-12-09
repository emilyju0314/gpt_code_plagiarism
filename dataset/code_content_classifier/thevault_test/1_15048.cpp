GameMode* GameMode::getInstance()
{
	static GameMode instance;
	return &instance;
}