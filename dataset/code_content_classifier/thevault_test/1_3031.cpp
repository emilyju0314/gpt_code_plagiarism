int Geometry::saveGeometry(pugi::xml_node root)
{
	//Make sure document pointer is valid
	if(!root)
		return 1;

	//Create the geometry node
	pugi::xml_node geom_node = root.append_child("geometry");
	geom_node.append_attribute("name") = name.c_str();
	geom_node.append_attribute("id") = unique_id.c_str();

	//Add mesh node to store triangle data
	pugi::xml_node mesh_node = geom_node.append_child("mesh");
	
	//Add the source node containing vertex positions
	writeVertexData(mesh_node, VDT_POSITION);

	//Add the source node containing vertex normals
	writeVertexData(mesh_node, VDT_NORMAL);

	//Add the source node containing vertex uv coordinates
	writeVertexData(mesh_node, VDT_UV);

	//Add the vertex node
	pugi::xml_node vertex_node = mesh_node.append_child("vertices");
	vertex_node.append_attribute("id") = (unique_id + "-Vtx").c_str();

	pugi::xml_node vinput_node = vertex_node.append_child("input");
	vinput_node.append_attribute("semantic") = "POSITION";
	vinput_node.append_attribute("source") = (std::string("#") + unique_id + "-Pos").c_str();

	//Add the triangles node
	writeTriangleData(mesh_node);

	return 0;
}