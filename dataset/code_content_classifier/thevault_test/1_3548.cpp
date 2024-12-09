void CShaderAPIDx8::SetStandardVertexShaderConstants( float fOverbright )
{
	LOCK_SHADERAPI();

	// Set a couple standard constants....
	Vector4D standardVertexShaderConstant( 0.0f, 1.0f, 2.0f, 0.5f );
	SetVertexShaderConstantInternal( VERTEX_SHADER_MATH_CONSTANTS0, standardVertexShaderConstant.Base(), 1 );

	// [ gamma, overbright, 1/3, 1/overbright ]
	standardVertexShaderConstant.Init( 1.0f/2.2f, fOverbright, 1.0f / 3.0f, 1.0f / fOverbright );
	SetVertexShaderConstantInternal( VERTEX_SHADER_MATH_CONSTANTS1, standardVertexShaderConstant.Base(), 1 );

#if 0
	int nModelIndex = VERTEX_SHADER_MODEL;

	// These point to the lighting and the transforms
	standardVertexShaderConstant.Init( 
		VERTEX_SHADER_LIGHTS,
		VERTEX_SHADER_LIGHTS + 5, 
        // Use COLOR instead of UBYTE4 since Geforce3 does not support it
        // vConst.w should be 3, but due to about hack, mul by 255 and add epsilon
		// 360 supports UBYTE4, so no fixup required
		(IsPC() || !IsX360()) ? 765.01f : 3.0f,
		 nModelIndex );	// DX8 has different constant packing
#endif

	SetVertexShaderConstantInternal( VERTEX_SHADER_LIGHT_INDEX, standardVertexShaderConstant.Base(), 1 );

	/*
	if ( g_pHardwareConfig->Caps().m_SupportsVertexShaders_3_0 )
	{
		Vector4D factors[4];
		factors[0].Init( 1, 0, 0, 0 );
		factors[1].Init( 0, 1, 0, 0 );
		factors[2].Init( 0, 0, 1, 0 );
		factors[3].Init( 0, 0, 0, 1 );
		SetVertexShaderConstantInternal( VERTEX_SHADER_DOT_PRODUCT_FACTORS, factors[0].Base(), 4 );
	}
*/

	float c[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	SetVertexShaderConstantInternal( VERTEX_SHADER_FLEXSCALE, c, 1 );
}