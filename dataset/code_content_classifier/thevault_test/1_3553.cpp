bool CShaderAPIDx8::OwnGPUResources( bool bEnable )
{
#if defined( _X360 )
	// no longer supporting, causes an unmeasurable benefit
	// code complexity and instability dictate it is better left off
	// modelfastpath and better batching has probably lessened the dense amount of constant setting
	// leaving code in case perf testing again shows constant setting to be an issue
	if ( !IsGPUOwnSupported() )
	{
		return false;
	}

	if ( m_bGPUOwned == bEnable )
	{
		return m_bGPUOwned;
	}

	if ( !bEnable )
	{
		Dx9Device()->GpuDisownAll();
	}
	else
	{
		// owned GPU constants can be set very fast, and must be in blocks of 4
		// owned constants are set via a peak watermark, otherwise the legacy method is used
		// there are 256, but the game only uses 217 (snapped to 220), leaving just enough room for shader literals
		COMPILE_TIME_ASSERT( VERTEX_SHADER_MODEL + 3*NUM_MODEL_TRANSFORMS == 217 );
		Dx9Device()->GpuOwnVertexShaderConstantF( 0, AlignValue( VERTEX_SHADER_MODEL + 3*NUM_MODEL_TRANSFORMS, 4 ) );
		// there are 256, but the game only utilizes 32, leaving lots of room for shader literals
		Dx9Device()->GpuOwnPixelShaderConstantF( 0, 32 );
	}

	bool bPrevious = m_bGPUOwned;
	m_bGPUOwned = bEnable;
	
	return bPrevious;
#else
	return false;
#endif
}