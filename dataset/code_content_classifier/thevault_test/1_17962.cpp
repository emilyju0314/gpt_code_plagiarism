Mesh UtilMesh::MakePlaneMesh()
{
	Uint32 numberOfLines = 60;
	float span = 5.0f;

	Mesh mesh = {};
	mesh.vertexCount = 0;
	mesh.vertices = (Vertex*)malloc(numberOfLines * 2 * sizeof(Vertex));
	mesh.isTexturable = false;

	// The plane is built in the xy plane (z == 0)
	for (Uint32 i = 0; i < numberOfLines; ++i)
	{
		float y = -(span / 2.0f) + i * (span / numberOfLines);
		float startX = -span / 2.0f;
		float endX = span / 2.0f;
		float z = 0.0f;

		Vertex start = {}, end = {};
		start.position = vec4(span / 2.0f, y, 0.0f, 1.0f);
		end.position = vec4(-span / 2.0f, y, 0.0f, 1.0f);
		start.vsOutColor = vec3(0, 0, 1);
		end.vsOutColor = vec3(0, 0, 1);

		AddLine(&mesh, start, end);
	}

	return mesh;
}