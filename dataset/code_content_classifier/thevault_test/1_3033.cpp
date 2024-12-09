void Geometry::writeTriangleData(pugi::xml_node root)
{
	pugi::xml_node triangles_node = root.append_child("triangles");
	triangles_node.append_attribute("count") = triangles.size();

	//Specify the format of the data
	pugi::xml_node input1 = triangles_node.append_child("input");
	input1.append_attribute("semantic") = "VERTEX";
	input1.append_attribute("source") = (std::string("#") + unique_id + "-Vtx").c_str();
	input1.append_attribute("offset") = 0;

	pugi::xml_node input2 = triangles_node.append_child("input");
	input2.append_attribute("semantic") = "NORMAL";
	input2.append_attribute("source") = (std::string("#") + unique_id + "-Normal").c_str();
	input2.append_attribute("offset") = 1;

	pugi::xml_node input3 = triangles_node.append_child("input");
	input3.append_attribute("semantic") = "TEXCOORD";
	input3.append_attribute("source") = (std::string("#") + unique_id + "-Tex").c_str();
	input3.append_attribute("offset") = 2;

	//Add the primitive node
	pugi::xml_node p_node = triangles_node.append_child("p");

	//Determine indent
	char indent[20];
	int depth = p_node.depth() - 1;
	int idx;
	for(idx = 0; idx < depth; idx++)
		indent[idx] = '\t';
	indent[idx] = '\0';

	//Add indices for each triangle to the node
	std::ostringstream tri_stream;
	tri_stream << std::endl << indent;
	int num_tris = triangles.size();
	int last_tri = num_tris - 1;
	int index = 0;
	for(int i = 0; i < num_tris; i++) {
		for(int j = 0; j < 3; j++) {
			tri_stream << triangles[i].vertices[j] << " ";
			tri_stream << triangles[i].normals[j] << " ";
			tri_stream << index;

			if(j != 2)
				tri_stream << "  ";

			index++;
		}

		if(i == last_tri)
			indent[depth - 1] = '\0';

		tri_stream << std::endl << indent;
	}

	//Build string from stream and add to the node
	std::string tri_string = tri_stream.str();
	p_node.text() = tri_string.c_str();

	return;
}