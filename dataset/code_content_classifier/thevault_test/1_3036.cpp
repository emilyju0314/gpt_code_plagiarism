void Geometry::cloneMesh(Geometry *g)
{
	int num_vertices = vertices.size();
	int num_normals = normals.size();
	int num_triangles = triangles.size();

	//Clone each vertex
	for(int i = 0; i < num_vertices; i++)
		g->addVertex(vertices[i]);

	//Clone each normal
	for(int i = 0; i < num_normals; i++)
		g->addNormal(normals[i]);

	//Clone each triangle
	for(int i = 0; i < num_triangles; i++)
		g->addTriangle(triangles[i]);
}