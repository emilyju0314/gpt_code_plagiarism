MeshLink *Mesh::FindByLabel ( const YARPString& label )
{
	int
		found = 0;
	MeshLink
		*cursor = root;

	while ( cursor != NULL && !found )
	{                              
		if ( label == cursor->GetLabel() )
		{
			found = 1;
		}
		else
		{
			cursor = cursor->BaseGetMeshNext();
		}
	}

	return cursor;
}