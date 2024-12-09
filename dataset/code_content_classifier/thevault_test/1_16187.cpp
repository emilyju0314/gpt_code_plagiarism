bool Application::LoadGame()
{
	bool ret = false;

	pugi::xml_document saveGame;
	pugi::xml_parse_result result = saveGame.load_file(SAVE_STATE_FILENAME);

	if (result == NULL) LOG("Could not load xml file: %s. pugi error: %s", SAVE_STATE_FILENAME, result.description())
	else ret = saveGame.child("game_state");


	p2List_item<Module*>* item = list_modules.getFirst();

	while (item != NULL)
	{
		item->data->LoadSaveData(saveGame);
		item = item->next;
	}

	loadGameRequested = false;

	return ret;
}