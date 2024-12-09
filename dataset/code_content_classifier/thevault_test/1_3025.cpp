int Instance::saveInstance(pugi::xml_node root, int *id, Transform *parent)
{
	//Make sure node pointer is valid
	if(!root)
		return 1;

	std::ostringstream name_stream;
	name_stream << original->getUniqueId() << "-Inst-" << (*id);
	*id = *id + 1;

	pugi::xml_node node = root.append_child("node");
	node.append_attribute("name") = name_stream.str().c_str();

	//Compound parent transform into the group's transform
	Transform total_t(t);
	if(parent)
		total_t.combine(parent);

	//Add the transform element
	total_t.save(node);

	//Add the geometry instance element
	pugi::xml_node instance_node = node.append_child("instance_geometry");
	instance_node.append_attribute("url") = (std::string("#") + original->getUniqueId()).c_str();

	return 0;
}