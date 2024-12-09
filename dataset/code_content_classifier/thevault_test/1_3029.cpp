void Geometry::cleanUp()
{
	unsigned int num_vertices = vbuffer_references.size();
	unsigned int num_triangles = triangles.size();
	unsigned int num_normals = nbuffer_references.size();
	unsigned int original_num_vertices = num_vertices;
	unsigned int original_num_normals = num_normals;
	unsigned int original_index;

	std::vector<Vector3D> new_list;
	std::vector<int> new_references;

	std::vector<unsigned int> removed_vertices;
	std::vector<unsigned int> removed_normals;
	unsigned int *vertex_remap = new unsigned int[num_vertices];
	unsigned int *normal_remap = new unsigned int[num_normals];

	for(unsigned int i = 0; i < num_vertices; i++)
		vertex_remap[i] = i;

	for(unsigned int i = 0; i < num_normals; i++)
		normal_remap[i] = i;
	
	//Find each vertex with 0 references
	original_index = 0;
	for(unsigned int i = 0; i < num_vertices; i++) {
		if(vbuffer_references[i] == 0) {
			removed_vertices.push_back(original_index);
		}
		else
		{
			new_list.push_back(vertices[i]);
			new_references.push_back(vbuffer_references[i]);
		}

		original_index++;
	}

	vertices = new_list;
	vbuffer_references = new_references;
	new_list.clear();
	new_references.clear();
	
	//Find each vertex with 0 references
	original_index = 0;
	for(unsigned int i = 0; i < num_normals; i++) {
		if(nbuffer_references[i] == 0) {
			removed_normals.push_back(original_index);
		}
		else
		{
			new_list.push_back(normals[i]);
			new_references.push_back(nbuffer_references[i]);
		}

		original_index++;
	}

	normals = new_list;
	nbuffer_references = new_references;
	new_list.clear();
	new_references.clear();

	//Generate remap from list of removed vertices/normals
	int removed_index = 0;
	int current_offset = 0;
	for(unsigned int i = 0; i < original_num_vertices; i++)
	{
		vertex_remap[i] = current_offset;
		if(i < removed_vertices.size() && i == removed_vertices[removed_index])
		{
			removed_index++;
			current_offset++;
		}
	}

	removed_index = 0;
	current_offset = 0;
	for(unsigned int i = 0; i < original_num_normals; i++)
	{
		normal_remap[i] = current_offset;
		if(i < removed_normals.size() && i == removed_normals[removed_index])
		{
			removed_index++;
			current_offset++;
		}
	}

	//Update indices in each triangle
	for(unsigned int i = 0; i < num_triangles; i++)
	{
		triangles[i].normals[0] -= normal_remap[triangles[i].normals[0]];
		triangles[i].normals[1] -= normal_remap[triangles[i].normals[1]];
		triangles[i].normals[2] -= normal_remap[triangles[i].normals[2]];

		triangles[i].vertices[0] -= vertex_remap[triangles[i].vertices[0]];
		triangles[i].vertices[1] -= vertex_remap[triangles[i].vertices[1]];
		triangles[i].vertices[2] -= vertex_remap[triangles[i].vertices[2]];
	}

	delete vertex_remap;
	delete normal_remap;
}