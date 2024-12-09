static void CommitVertexShaderConstantRange( D3DDeviceWrapper *pDevice, const DynamicState_t &desiredState,
	DynamicState_t &currentState, bool bForce, int nFirstConstant, int nCount )
{
	if ( IsX360() )
	{
		// invalid code path for 360, not coded for 360 GPU constant awareness
		Assert( 0 );
		return;
	}

	int nFirstCommit = nFirstConstant;
	int nCommitCount = 0;

	for ( int i = 0; i < nCount; ++i )
	{
		int nVar = nFirstConstant + i; 

		bool bDifferentValue = bForce || ( desiredState.m_pVectorVertexShaderConstant[nVar] != currentState.m_pVectorVertexShaderConstant[nVar] );
		if ( !bDifferentValue )
		{
			if ( nCommitCount != 0 )
			{
				// flush the prior range
				pDevice->SetVertexShaderConstantF( nFirstCommit, desiredState.m_pVectorVertexShaderConstant[nFirstCommit].Base(), nCommitCount );

				memcpy( &currentState.m_pVectorVertexShaderConstant[nFirstCommit], 
					&desiredState.m_pVectorVertexShaderConstant[nFirstCommit], nCommitCount * 4 * sizeof(float) );
			}

			// start of new range
			nFirstCommit = nVar + 1;
			nCommitCount = 0;
		}
		else
		{
			++nCommitCount;
		}
	}

	if ( nCommitCount != 0 )
	{
		// flush range
		pDevice->SetVertexShaderConstantF( nFirstCommit, desiredState.m_pVectorVertexShaderConstant[nFirstCommit].Base(), nCommitCount );

		memcpy( &currentState.m_pVectorVertexShaderConstant[nFirstCommit], 
			&desiredState.m_pVectorVertexShaderConstant[nFirstCommit], nCommitCount * 4 * sizeof(float) );
	}
}