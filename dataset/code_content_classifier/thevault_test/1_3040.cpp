int Scene::load(const char *filename)
{
	pugi::xml_document load_file;
	pugi::xml_parse_result result = load_file.load_file(filename);

	//Exit if the file could not be parsed
	if(result.status != pugi::xml_parse_status::status_ok)
	{
		return 1;
	}

	//Get the base node of the file
	if(load_file.child("COLLADA"))
	{
		pugi::xml_node root = load_file.child("COLLADA");

		//Get the scene node
		if(!(root.child("scene")))
			return 1;

		pugi::xml_node scene_node = root.child("scene");

		//Get the name of the visual scene to load
		if(!(scene_node.child("instance_visual_scene")))
			return 1;

		pugi::xml_node instance_scene_node = scene_node.child("instance_visual_scene");

		//Trim off the # character at the beginning of the url
		const char* scene_url = instance_scene_node.attribute("url").as_string();
		if(scene_url[0] == '#')
			scene_url++;
		else
			return 1;

		//Read each child node
		for(pugi::xml_node top_node = root.first_child(); top_node; top_node = top_node.next_sibling())
		{
			if(!strcmp(top_node.name(), "asset"))
			{
				//TODO: Process metadata
			}
			else if(!strcmp(top_node.name(), "library_geometries"))
			{
				for(pugi::xml_node geom_node = top_node.first_child(); geom_node; geom_node = geom_node.next_sibling())
				{
					if(!strcmp(geom_node.name(), "geometry"))
					{
						Geometry *g = new Geometry();
						if(!g->readGeometry(geom_node))
						{
							g->setVisibility(false);
							addObject(g);
						}
						else
						{
							delete g;
						}
					}
				}
			}
			else if(!strcmp(top_node.name(), "library_visual_scenes"))
			{
				//Only load the scene pointed to by instance_visual_scene
				for(pugi::xml_node vscene_node = top_node.first_child(); vscene_node; vscene_node = vscene_node.next_sibling())
				{
					if(!strcmp(vscene_node.name(), "visual_scene") && !strcmp(vscene_node.attribute("id").as_string(), scene_url))
					{
						//Iterate over each node in the scene
						for(pugi::xml_node node = vscene_node.first_child(); node; node = node.next_sibling())
						{
							//Add each geometry instance
							if(!strcmp(node.name(), "node"))
							{
								loadNode(node, NULL);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}