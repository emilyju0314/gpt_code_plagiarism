bool j1App::DoUpdate()
{
	bool ret = true;
	j1Module* pModule = NULL;

	for(size_t i = 0; i < modules.size() && ret == true; i++)
	{
		pModule = modules[i];

		if(pModule->active == false) {
			continue;
		}

		ret = modules[i]->Update(dt);
	}

	return ret;
}