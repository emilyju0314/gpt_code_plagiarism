Mesh UtilMesh::MakeNormalMesh(Mesh *original, float normalLength)
{
	Mesh normalMesh = {};
	normalMesh.vertexCount = 0;
	normalMesh.vertices = (Vertex*)malloc(2 * original->vertexCount * sizeof(Vertex));
	normalMesh.isTexturable = false;

	for (Uint32 i = 0; i < original->vertexCount; ++i)
	{
		Vertex start = {};
		start.position = original->vertices[i].position;
		start.vsOutColor = vec3(1.0f, 1.0f, 0.0f);

		Vertex end = {};
		end.position = start.position + vec4(original->vertices[i].normal, 0.0f) * normalLength;
		end.vsOutColor = vec3(1.0f, 1.0f, 0.0f);

		normalMesh.vertices[normalMesh.vertexCount++] = start;
		normalMesh.vertices[normalMesh.vertexCount++] = end;
	}

	return normalMesh;
}