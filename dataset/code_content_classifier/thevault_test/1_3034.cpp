void Geometry::filter()
{
	int num_filters = filters.size();
	for(int i = 0; i < num_filters; i++)
		filters[i]->run(this);
}