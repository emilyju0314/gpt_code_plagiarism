void CShaderAPIDx8::SetIntegerVertexShaderConstant( int var, int const* pVec, int numIntVecs, bool bForce )
{
	Assert( pVec );
	Assert( var + numIntVecs <= g_pHardwareConfig->NumIntegerVertexShaderConstants() );

	if ( IsPC() && !bForce && memcmp( pVec, &m_DesiredState.m_pIntegerVertexShaderConstant[var], numIntVecs * sizeof( IntVector4D ) ) == 0 )
	{
		return;
	}

	if ( IsPC() || IsPS3() )
	{
		Dx9Device()->SetVertexShaderConstantI( var, pVec, numIntVecs );
		memcpy( &m_DynamicState.m_pIntegerVertexShaderConstant[var], pVec, numIntVecs * sizeof(IntVector4D) );
	}

	if ( IsX360() )
	{
		if ( !IsGPUOwnSupported() || !m_bGPUOwned )
		{
			Dx9Device()->SetVertexShaderConstantI( var, pVec, numIntVecs );
			if ( IsGPUOwnSupported() )
			{
				memcpy( &m_DynamicState.m_pIntegerVertexShaderConstant[var], pVec, numIntVecs * sizeof(IntVector4D) );
			}
		}
		else if ( var + numIntVecs > m_MaxIntegerVertexShaderConstant )
		{
			m_MaxIntegerVertexShaderConstant = var + numIntVecs;
			Assert( m_MaxIntegerVertexShaderConstant <= 16 );
		}
	}

	memcpy( &m_DesiredState.m_pIntegerVertexShaderConstant[var], pVec, numIntVecs * sizeof(IntVector4D) );
}