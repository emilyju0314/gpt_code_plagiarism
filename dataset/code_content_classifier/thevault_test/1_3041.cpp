void Scene::consolidate()
{
	Geometry *entire_scene = new Geometry("scene");

	//Combine all objects
	for(unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i]->cleanUp();
		if(objects[i]->isVisible())
		{
			objects[i]->combineInto(entire_scene, NULL);
		}
	}

	//Delete all objects
	for(unsigned int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
	objects.clear();

	//Add super-object to scene
	entire_scene->cleanUp();
	addObject(entire_scene);
}