void CShaderAPIDx8::SetBooleanVertexShaderConstant( int var, int const* pVec, int numBools, bool bForce )
{
	Assert( pVec );
	Assert( var + numBools <= g_pHardwareConfig->NumBooleanVertexShaderConstants() );

	if ( IsPC() && !bForce && memcmp( pVec, &m_DesiredState.m_pBooleanVertexShaderConstant[var], numBools * sizeof( BOOL ) ) == 0 )
	{
		return;
	}

	if ( IsPC() || IsPS3() )
	{
		Dx9Device()->SetVertexShaderConstantB( var, pVec, numBools );
		memcpy( &m_DynamicState.m_pBooleanVertexShaderConstant[var], pVec, numBools * sizeof(BOOL) );
	}

	if ( IsX360() )
	{
		if ( !IsGPUOwnSupported() || !m_bGPUOwned )
		{
			Dx9Device()->SetVertexShaderConstantB( var, pVec, numBools );
			if ( IsGPUOwnSupported() )
			{
				memcpy( &m_DynamicState.m_pBooleanVertexShaderConstant[var], pVec, numBools * sizeof(BOOL) );
			}
		}
		else if ( var + numBools > m_MaxBooleanVertexShaderConstant )
		{
			m_MaxBooleanVertexShaderConstant = var + numBools;
			Assert( m_MaxBooleanVertexShaderConstant <= 16 );
		}
	}

	memcpy( &m_DesiredState.m_pBooleanVertexShaderConstant[var], pVec, numBools * sizeof(BOOL) );
}