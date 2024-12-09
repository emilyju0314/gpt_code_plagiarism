void Mesh::Clear()
{
	MeshLink
		*cursor = root;

	if ( autoClear != 0 && autoClear != -1 )
	{
		while ( cursor != NULL )
		{
			cursor = root->BaseGetMeshNext();
			delete root;
			root = cursor;
		}
	}
}