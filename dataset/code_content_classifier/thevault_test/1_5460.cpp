static void generatePhongNormals(span<ModelPhong::Vertex> const vertices)
{
	ASSERT(vertices.size() % 3 == 0);

	for (size_t i = 0; i < vertices.size(); i += 3) {
		vec3 const& v0 = vertices[i + 0].pos;
		vec3 const& v1 = vertices[i + 1].pos;
		vec3 const& v2 = vertices[i + 2].pos;

		vec3 const normal = normalize(cross(v1 - v0, v2 - v0));
		vertices[i + 0].normal = normal;
		vertices[i + 1].normal = normal;
		vertices[i + 2].normal = normal;
	}
}