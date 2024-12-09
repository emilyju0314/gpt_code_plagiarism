bool ModuleMap::LoadTilesetImage(pugi::xml_node& tileset_node, TileSet* set)
{
	bool ret = true;
	pugi::xml_node image = tileset_node.child("image");

	if (image == NULL)
	{
		//LOG("Error parsing tileset xml file: Cannot find 'image' tag.");
		ret = false;
	}
	else
	{
		// L03: DONE 4: Load Tileset image
		std::string imageS = image.attribute("source").as_string();
	
		std::string tmp = folder + imageS;
		set->texture = App->textures->Load(tmp);
	}

	return ret;
}