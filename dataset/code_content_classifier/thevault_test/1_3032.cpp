void Geometry::writeVertexData(pugi::xml_node root, vertex_data_type data_type)
{
	//Determine the name of this source node
	std::string vsn_name;
	switch(data_type) {
	case VDT_POSITION:
		vsn_name = unique_id + "-Pos";
		break;
	case VDT_NORMAL:
		vsn_name = unique_id + "-Normal";
		break;
	case VDT_UV:
		vsn_name = unique_id + "-Tex";
		break;
	default:
		return;
	}

	//Determine the stride
	int stride = 2;
	if(data_type == VDT_POSITION || data_type == VDT_NORMAL)
		stride = 3;

	//Determine the count
	int count = 0;
	if(data_type == VDT_POSITION)
		count = vertices.size();
	else if(data_type == VDT_NORMAL)
		count = normals.size();
	else
		count = triangles.size() * 3;

	//Create the source node
	pugi::xml_node source_node = root.append_child("source");
	source_node.append_attribute("id") = vsn_name.c_str();

	std::string vsna_name = vsn_name + "-array";
	pugi::xml_node vfa_node = source_node.append_child("float_array");
	vfa_node.append_attribute("id") = vsna_name.c_str();
	vfa_node.append_attribute("count") = stride * count;

	//Create indentation for newlines
	char indent[20];
	int depth = vfa_node.depth() - 2;
	int idx;
	for(idx = 0; idx < depth; idx++)
		indent[idx] = '\t';
	indent[idx] = '\0';

	//Add each data value to the node
	std::ostringstream va_string_stream;
	va_string_stream << std::setiosflags(std::ios::showpoint) << std::endl << indent;
	if(data_type == VDT_POSITION) {
		//Write out per vertex information
		int num_vertices = vertices.size();
		for(int i = 0; i < num_vertices; i++) {
			va_string_stream << DEC_FORMAT << vertices[i].x << " ";
			va_string_stream << DEC_FORMAT << vertices[i].y << " ";
			va_string_stream << DEC_FORMAT << vertices[i].z << std::endl << indent;
		}
	} else if(data_type == VDT_NORMAL) {
		//Write out each normal in the buffer
		int num_normals = normals.size();
		for(int i = 0; i < num_normals; i++) {
			va_string_stream << DEC_FORMAT << normals[i].x << " ";
			va_string_stream << DEC_FORMAT << normals[i].y << " ";
			va_string_stream << DEC_FORMAT << normals[i].z << std::endl << indent;
		}
	} else {
		//Write out per triangle-vertex information
		int num_tris = triangles.size();
		
		switch(data_type){
		case VDT_UV:
			for(int i = 0; i < num_tris; i++) {
				for(int j = 0; j < 3; j++) {
					va_string_stream << DEC_FORMAT << triangles[i].uvs[j].u << " ";
					va_string_stream << DEC_FORMAT << triangles[i].uvs[j].v << std::endl << indent;
				}
			}
			break;
		}
	}

	//Build the string from the stream and copy to the node
	std::string va_string = va_string_stream.str();
	vfa_node.text() = va_string.c_str();

	//Add the technique node
	pugi::xml_node vtechnique_node = source_node.append_child("technique_common");
	pugi::xml_node vta_node = vtechnique_node.append_child("accessor");
	vta_node.append_attribute("source") = (std::string("#") + vsna_name).c_str();
	vta_node.append_attribute("count") = count;
	vta_node.append_attribute("stride") = stride;

	if(data_type == VDT_POSITION || data_type == VDT_NORMAL) {
		//3D points
		pugi::xml_node param1 = vta_node.append_child("param");
		param1.append_attribute("name") = "X";
		param1.append_attribute("type") = "float";
		pugi::xml_node param2 = vta_node.append_child("param");
		param2.append_attribute("name") = "Y";
		param2.append_attribute("type") = "float";
		pugi::xml_node param3 = vta_node.append_child("param");
		param3.append_attribute("name") = "Z";
		param3.append_attribute("type") = "float";
	} else {
		//2D points
		pugi::xml_node param1 = vta_node.append_child("param");
		param1.append_attribute("name") = "S";
		param1.append_attribute("type") = "float";
		pugi::xml_node param2 = vta_node.append_child("param");
		param2.append_attribute("name") = "T";
		param2.append_attribute("type") = "float";
	}

	return;
}