bool j1App::PreUpdate()
{
	bool ret = true;
	j1Module* pModule = NULL;

	for(size_t i = 0; i < modules.size() && ret == true; i++)
	{
		pModule = modules[i];
		if (pModule->active == false) {
			continue;
		}
		ret = modules[i]->PreUpdate();
	}

	return ret;
}