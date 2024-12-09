void Subdivide::run(Geometry *g)
{
	//Run the subdivision algorithm levels times
	for(int i = 0; i < levels; i++)
		subd(g);

	return;
}