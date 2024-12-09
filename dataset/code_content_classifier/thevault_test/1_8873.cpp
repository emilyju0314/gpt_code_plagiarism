bool j1App::PostUpdate()
{
	bool ret = true;
	std::list<j1Module*>::const_iterator item = modules.begin();
	j1Module* pModule = NULL;

	for (; item != modules.end() && ret; ++item)
	{
		pModule = *item;

		if (!pModule->active)
		{
			continue;
		}

		ret = (*item)->PostUpdate();
	}

	return ret;
}