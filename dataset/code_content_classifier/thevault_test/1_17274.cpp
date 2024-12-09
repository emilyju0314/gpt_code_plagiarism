inline bool show_face(block_id face, block_id neighbor, int face_id)
{
	bool hide = is_transparent(neighbor);

	if (face == id_water && neighbor == id_water)
	{
		hide = false;
	}
	else if (face == id_glass && neighbor == id_glass)
	{
		hide = false;
	}

	return hide;
}