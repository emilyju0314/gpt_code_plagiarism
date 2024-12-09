void CShaderAPIDx8::WriteShaderConstantsToGPU()
{
#if defined( _X360 )
	if ( !IsGPUOwnSupported() || !m_bGPUOwned )
	{
		return;
	}

	// vector vertex constants can just blast their set range
	if ( m_MaxVectorVertexShaderConstant )
	{
		if ( m_bGPUOwned )
		{
			// faster path, write directly into GPU command buffer, bypassing shadow state
			// can only set what is actually owned
			Assert( m_MaxVectorVertexShaderConstant <= VERTEX_SHADER_MODEL + 3*NUM_MODEL_TRANSFORMS );
			int numVectors = AlignValue( m_MaxVectorVertexShaderConstant, 4 );
			BYTE* pCommandBufferData;
			Dx9Device()->GpuBeginVertexShaderConstantF4( 0, (D3DVECTOR4**)&pCommandBufferData, numVectors );
			memcpy( pCommandBufferData, m_DesiredState.m_pVectorVertexShaderConstant[0].Base(), numVectors * (sizeof( float ) * 4) );
			Dx9Device()->GpuEndVertexShaderConstantF4();
		}
		else
		{
			Dx9Device()->SetVertexShaderConstantF( 0, m_DesiredState.m_pVectorVertexShaderConstant[0].Base(), m_MaxVectorVertexShaderConstant );
		}

		memcpy( m_DynamicState.m_pVectorVertexShaderConstant[0].Base(), m_DesiredState.m_pVectorVertexShaderConstant[0].Base(), m_MaxVectorVertexShaderConstant * 4 * sizeof(float) );
		m_MaxVectorVertexShaderConstant = 0;
	}

	if ( m_MaxVectorPixelShaderConstant )
	{
		if ( m_bGPUOwned )
		{
			// faster path, write directly into GPU command buffer, bypassing shadow state
			// can only set what is actually owned
			Assert( m_MaxVectorPixelShaderConstant <= 32 );
			int numVectors = AlignValue( m_MaxVectorPixelShaderConstant, 4 );
			BYTE* pCommandBufferData;
			Dx9Device()->GpuBeginPixelShaderConstantF4( 0, (D3DVECTOR4**)&pCommandBufferData, numVectors );
			memcpy( pCommandBufferData, m_DesiredState.m_pVectorPixelShaderConstant[0].Base(), numVectors * (sizeof( float ) * 4) );
			Dx9Device()->GpuEndPixelShaderConstantF4();
		}
		else
		{
			Dx9Device()->SetPixelShaderConstantF( 0, m_DesiredState.m_pVectorPixelShaderConstant[0].Base(), m_MaxVectorPixelShaderConstant );
		}

		memcpy( m_DynamicState.m_pVectorPixelShaderConstant[0].Base(), m_DesiredState.m_pVectorPixelShaderConstant[0].Base(), m_MaxVectorPixelShaderConstant * 4 * sizeof(float) );
		m_MaxVectorPixelShaderConstant = 0;
	}

	// boolean and integer constants can just blast their set range
	// these are currently extremely small in number, if this changes they may benefit from a fast path pattern
	if ( m_MaxBooleanVertexShaderConstant )
	{
		Dx9Device()->SetVertexShaderConstantB( 0, m_DesiredState.m_pBooleanVertexShaderConstant, m_MaxBooleanVertexShaderConstant );
		memcpy( m_DynamicState.m_pBooleanVertexShaderConstant, m_DesiredState.m_pBooleanVertexShaderConstant, m_MaxBooleanVertexShaderConstant * sizeof(BOOL) );
		m_MaxBooleanVertexShaderConstant = 0;
	}
	if ( m_MaxIntegerVertexShaderConstant )
	{
		Dx9Device()->SetVertexShaderConstantI( 0, (int *)m_DesiredState.m_pIntegerVertexShaderConstant, m_MaxIntegerVertexShaderConstant );
		memcpy( m_DynamicState.m_pIntegerVertexShaderConstant[0].Base(), m_DesiredState.m_pIntegerVertexShaderConstant[0].Base(), m_MaxIntegerVertexShaderConstant * sizeof(IntVector4D) );
		m_MaxIntegerVertexShaderConstant = 0;
	}

	if ( m_MaxBooleanPixelShaderConstant )
	{
		Dx9Device()->SetPixelShaderConstantB( 0, m_DesiredState.m_pBooleanPixelShaderConstant, m_MaxBooleanPixelShaderConstant );
		memcpy( m_DynamicState.m_pBooleanPixelShaderConstant, m_DesiredState.m_pBooleanPixelShaderConstant, m_MaxBooleanPixelShaderConstant * sizeof(BOOL) );
		m_MaxBooleanPixelShaderConstant = 0;
	}

	// integer pixel constants are not used, so not supporting
#if 0
	if ( m_MaxIntegerPixelShaderConstant )
	{
		Dx9Device()->SetPixelShaderConstantI( 0, (int *)m_DesiredState.m_pIntegerPixelShaderConstant, m_MaxIntegerPixelShaderConstant );
		memcpy( m_DynamicState.m_pIntegerPixelShaderConstant[0].Base(), m_DesiredState.m_pIntegerPixelShaderConstant[0].Base(), m_MaxIntegerPixelShaderConstant * sizeof(IntVector4D) );
		m_MaxIntegerPixelShaderConstant = 0;
	}
#endif
#endif
}