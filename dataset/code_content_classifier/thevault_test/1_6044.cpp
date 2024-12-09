MeshLink *Mesh::AddLink ( const YARPString& label, const YARPString& srcLabel, const YARPString& destLabel )
{
	int
		success = 0;
	MeshLink
		*link,
		*srcLink,
		*destLink;

	link = LabelledLink ( label );
	srcLink = LabelledLink ( srcLabel );
	destLink = LabelledLink ( destLabel );

	if ( autoClear == -1 )
	{
		autoClear = 1;
	}

	if ( link != NULL )
	{
		link->SetSource ( srcLink );
		link->SetDest ( destLink );
		success = 1;
	}

	return success ? link : (MeshLink *) NULL;
}