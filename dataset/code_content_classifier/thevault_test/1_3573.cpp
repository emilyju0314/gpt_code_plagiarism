void CShaderAPIDx8::SetIntegerPixelShaderConstant( int var, int const* pVec, int numIntVecs, bool bForce )
{
	Assert( pVec );
	Assert( var + numIntVecs <= g_pHardwareConfig->NumIntegerPixelShaderConstants() );

	if ( IsPC() && !bForce && memcmp( pVec, &m_DesiredState.m_pIntegerPixelShaderConstant[var], numIntVecs * sizeof( IntVector4D ) ) == 0 )
	{
		return;
	}

	if ( IsPC() || IsPS3() )
	{
		Dx9Device()->SetPixelShaderConstantI( var, pVec, numIntVecs );
		memcpy( &m_DynamicState.m_pIntegerPixelShaderConstant[var], pVec, numIntVecs * sizeof(IntVector4D) );
	}

	if ( IsX360() )
	{
		if ( !IsGPUOwnSupported() || !m_bGPUOwned )
		{
			Dx9Device()->SetPixelShaderConstantI( var, pVec, numIntVecs );
			memcpy( &m_DynamicState.m_pIntegerPixelShaderConstant[var], pVec, numIntVecs * sizeof(IntVector4D) );
		}
		else if ( var + numIntVecs > m_MaxIntegerPixelShaderConstant )
		{
			m_MaxIntegerPixelShaderConstant = var + numIntVecs;
			Assert( m_MaxBooleanPixelShaderConstant <= 16 );
		}
	}

	memcpy( &m_DesiredState.m_pIntegerPixelShaderConstant[var], pVec, numIntVecs * sizeof(IntVector4D) );
}