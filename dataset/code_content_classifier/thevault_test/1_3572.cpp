void CShaderAPIDx8::SetBooleanPixelShaderConstant( int var, int const* pVec, int numBools, bool bForce )
{
	Assert( pVec );
	Assert( var + numBools <= g_pHardwareConfig->NumBooleanPixelShaderConstants() );

	if ( IsPC() && !bForce && memcmp( pVec, &m_DesiredState.m_pBooleanPixelShaderConstant[var], numBools * sizeof( BOOL ) ) == 0 )
	{
		return;
	}

	if ( IsPC() || IsPS3() )
	{
		Dx9Device()->SetPixelShaderConstantB( var, pVec, numBools );
		memcpy( &m_DynamicState.m_pBooleanPixelShaderConstant[var], pVec, numBools * sizeof(BOOL) );
	}

	if ( IsX360() )
	{
		if ( !IsGPUOwnSupported() || !m_bGPUOwned )
		{
			Dx9Device()->SetPixelShaderConstantB( var, pVec, numBools );
			memcpy( &m_DynamicState.m_pBooleanPixelShaderConstant[var], pVec, numBools * sizeof(BOOL) );
		}
		else if ( var + numBools > m_MaxBooleanPixelShaderConstant )
		{
			m_MaxBooleanPixelShaderConstant = var + numBools;
			Assert( m_MaxBooleanPixelShaderConstant <= 16 );
		}
	}

	memcpy( &m_DesiredState.m_pBooleanPixelShaderConstant[var], pVec, numBools * sizeof(BOOL) );
}