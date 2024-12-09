int Scene::addObject(Geometry *g)
{
	int id = objects.size();
	objects.push_back(g);

	return id;
}