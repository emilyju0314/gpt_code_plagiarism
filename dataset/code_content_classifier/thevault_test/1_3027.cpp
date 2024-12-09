int Geometry::addNormal(Vector3D n)
{
	int index = normals.size();
	normals.push_back(n);
	nbuffer_references.push_back(0);

	return index;
}