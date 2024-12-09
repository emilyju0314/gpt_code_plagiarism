VertexFormat_t CShaderAPIDx8::ComputeVertexUsage( int num, StateSnapshot_t* pIds ) const
{
	LOCK_SHADERAPI();
	if (num == 0)
		return 0;

	// We don't have to all sorts of crazy stuff if there's only one snapshot
	if ( num == 1 )
	{
		const ShadowShaderState_t& state = m_TransitionTable.GetSnapshotShader( pIds[0] );
		return state.m_VertexUsage;
	}

	Assert( pIds );

	// Aggregating vertex formats is a little tricky;
	// For example, what do we do when two passes want user data? 
	// Can we assume they are the same? For now, I'm going to
	// just print a warning in debug.

	VertexCompressionType_t compression = VERTEX_COMPRESSION_INVALID;
	int userDataSize = 0;
	int numBones = 0;
	int texCoordSize[VERTEX_MAX_TEXTURE_COORDINATES] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int flags = 0;

	for (int i = num; --i >= 0; )
	{
		const ShadowShaderState_t& state = m_TransitionTable.GetSnapshotShader( pIds[i] );
		VertexFormat_t fmt = state.m_VertexUsage;
		flags |= VertexFlags(fmt);

		VertexCompressionType_t newCompression = CompressionType( fmt );
		if ( ( compression != newCompression ) && ( compression != VERTEX_COMPRESSION_INVALID ) )
		{
			Warning("Encountered a material with two passes that specify different vertex compression types!\n");
			compression = VERTEX_COMPRESSION_NONE; // Be safe, disable compression
		}

		int newNumBones = NumBoneWeights(fmt);
		if ((numBones != newNumBones) && (newNumBones != 0))
		{
			if (numBones != 0)
			{
				Warning("Encountered a material with two passes that use different numbers of bones!\n");
			}
			numBones = newNumBones;
		}

		int newUserSize = UserDataSize(fmt);
		if ((userDataSize != newUserSize) && (newUserSize != 0))
		{
			if (userDataSize != 0)
			{
				Warning("Encountered a material with two passes that use different user data sizes!\n");
			}
			userDataSize = newUserSize;
		}

		for ( int j = 0; j < VERTEX_MAX_TEXTURE_COORDINATES; ++j )
		{
			int newSize = TexCoordSize( j, fmt );
			if ( ( texCoordSize[j] != newSize ) && ( newSize != 0 ) )
			{
				if ( texCoordSize[j] != 0 ) 
				{
					Warning("Encountered a material with two passes that use different texture coord sizes!\n");
				}
				if ( texCoordSize[j] < newSize )
				{
					texCoordSize[j] = newSize;
				}
			}
		}
	}

	return MeshMgr()->ComputeVertexFormat( flags, VERTEX_MAX_TEXTURE_COORDINATES, 
		texCoordSize, numBones, userDataSize );
}