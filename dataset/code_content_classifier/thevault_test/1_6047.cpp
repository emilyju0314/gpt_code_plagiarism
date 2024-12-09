int Mesh::Store ( ostream& os, int style )
{
	int
    	verbose = ( ( style & FORMAT ) == PROSE_FORMAT ),
		exhaustive = ( ( style & CONTENT ) == EXHAUSTIVE_CONTENT ),
		failed = 0;
	MeshLink
		*cursor = root;

	if ( cursor != NULL )
	{
		while ( cursor->BaseGetMeshNext() != NULL )
		{
			cursor = cursor->BaseGetMeshNext();
		}

		while ( cursor != NULL && !failed )
		{
			os << cursor->GetLabel() << TabChar;
			if ( verbose )	os << "FROM " << TabChar;
			if ( cursor->BaseGetSource() != NULL )
			{
				os << cursor->BaseGetSource()->GetLabel() << TabChar;
			}
			else
			{
				os << NullName << TabChar;
			}
			if ( verbose )	os << "TO " << TabChar;
			if ( cursor->BaseGetDest() != NULL )
			{
				os << cursor->BaseGetDest()->GetLabel() << TabChar;
			}
			else
			{
				os << NullName << TabChar;
			}

			if ( verbose )	os << "( ";
			if ( !cursor->Write ( os, style ) )
			{
				os << "< Couldn't write object in ";
				os << ( verbose ? "Prose-like" : "Concise" );
				os << " format with ";
				os << ( exhaustive ? "Exhaustive" : "Minimal" );
                os << " content >";

				failed = 1;
			}

			if ( verbose )		os << " )";
			os << endl;

			cursor = cursor->BaseGetMeshPrev();
		}

	}

	//	Terminate file
	if ( verbose )
	{
		os << NullName << " : EndOfMesh" << endl;
	}
	else
	{
		os << NullName;
	}

	return !failed;
}