bool ModuleScene::ChangeCurrentScene(uint index, int frames)
{
	if (isChangingScene)return true;
	isChangingScene = true;
	this->index = (SCENES)index;
	App->debug->ResetDebug();
	currentScene->CleanUp();
	currentScene = scenes[index];
	currentScene->Start();
	

	return true;
}