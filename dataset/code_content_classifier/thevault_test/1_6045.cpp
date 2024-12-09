MeshLink *Mesh::LabelledLink ( const YARPString& label )
{
	MeshLink
		*link = NULL;

	if ( !(label==NullName))
	{
		link = FindByLabel ( label );
		if ( link == NULL )
		{
			link = CreateLink();
			if ( link != NULL )
			{
				link->SetLabel ( label );
				link->SetOwner ( this );
			}
		}
	}

	return link;
}