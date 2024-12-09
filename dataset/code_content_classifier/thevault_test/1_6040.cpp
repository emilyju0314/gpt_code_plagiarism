void MeshLink::SetOwner ( Mesh *mesh )
{
  MeshLink *cursor;
	if ( owner != NULL )
	{
		if ( owner->root == this )	owner->root = meshNext;
		if ( meshPrev != NULL )		meshPrev->meshNext = meshNext;
		if ( meshNext != NULL )		meshNext->meshPrev = meshPrev;
		meshPrev = meshNext = NULL;
		owner = NULL;
	}
	if ( mesh != NULL )
	{
		//	Connect to new owner
		owner = mesh;
		cursor = mesh->root;
		if ( cursor != NULL )
		  {
		    while ( cursor->meshNext != NULL )
		      {
			cursor = cursor->meshNext;
		      }
		    cursor->meshNext = this;
		  }
		else
		  {
		    mesh->root = this;
		  }
		meshPrev = cursor;
		meshNext = NULL;
	}
}