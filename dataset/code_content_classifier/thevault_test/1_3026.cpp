int Geometry::addVertex(Vector3D v)
{
	int index = vertices.size();
	vertices.push_back(v);
	vbuffer_references.push_back(0);

	return index;
}