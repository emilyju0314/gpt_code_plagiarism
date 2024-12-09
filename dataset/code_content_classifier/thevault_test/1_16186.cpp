UpdateStatus Application::Update()
{
	if (isExiting) return UPDATE_STOP;
	OPTICK_EVENT();
	UpdateStatus ret = UPDATE_CONTINUE;
	p2List_item<Module*>* item = list_modules.getFirst();

	while (item != NULL && ret == UPDATE_CONTINUE)
	{
		if (item->data->IsEnabled())
			ret = item->data->PreUpdate();
		item = item->next;
	}

	item = list_modules.getFirst();

	while (item != NULL && ret == UPDATE_CONTINUE)
	{
		if (item->data->IsEnabled())
			ret = item->data->Update();
		item = item->next;
	}

	item = list_modules.getFirst();

	while (item != NULL && ret == UPDATE_CONTINUE)
	{
		if (item->data->IsEnabled())
			ret = item->data->PostUpdate();
		item = item->next;
	}

	//// L02: DONE 1: This is a good place to call Load / Save methods
	if (saveGameRequested == true) SaveGame();
	if (loadGameRequested == true) LoadGame();

	// Update globalTime
	globalTime.Update();

	deltaTime = globalTime.getDeltaTime();

	if (deltaTime <= (1.0f / fps))
	{
		sleepTime = ((1.0f / fps) - deltaTime) * 1000;
		Sleep(sleepTime);
	}

	globalTime.Reset();

	ShowTime();

	return ret;
}