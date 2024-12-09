int Geometry::addTriangle(Triangle t)
{
	int index = triangles.size();
	triangles.push_back(t);

	//Update the vertex reference counts
	vbuffer_references[t.vertices[0]]++;
	vbuffer_references[t.vertices[1]]++;
	vbuffer_references[t.vertices[2]]++;

	//Update the normal reference counts
	nbuffer_references[t.normals[0]]++;
	nbuffer_references[t.normals[1]]++;
	nbuffer_references[t.normals[2]]++;

	return index;
}