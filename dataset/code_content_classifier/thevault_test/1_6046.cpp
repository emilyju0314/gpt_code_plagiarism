int Mesh::Load ( istream& is, int style )
{
	char
		buf[YARP_STRING_LEN];
	int
		verbose = ( ( style & FORMAT ) == PROSE_FORMAT ),
		failed = 0,
		done = 0;
	YARPString
		label,
		srcLabel,
		destLabel;
	MeshLink
		*link;

	do
	{
    	is >> buf;
		label = buf;

		if ( !(label == NullName ) )
		{
			if ( verbose )	is >> buf;		//	Eliminate "FROM"

			is >> buf;
			srcLabel = buf;
			if ( verbose )	is >> buf;		//	Eliminate "TO"

			is >> buf;
			destLabel = buf;
			if ( verbose )	is >> buf;		//	Eliminate "("

			link = AddLink ( label, srcLabel, destLabel );
			if ( link != NULL )
			{
				if ( !link->Read ( is, style ) )
				{
					//	Failed
					failed = 1;
				}
				else
            	{
					if ( verbose )	is >> buf;	//	Eliminate ")"
				}
			}
		}
		else
		{
			if ( verbose )
            {
				is >> buf;					//	Eliminate ":"
				is >> buf;					//	Eliminate "EndOfMesh"
            }
			done = 1;
		}
		if ( is.eof() )	{	done = 1;	}
	} while ( !done && !failed );

	return !failed;
}