void CShaderAPIDx8::SetDepthFeatheringShaderConstants( int iConstant, float fDepthBlendScale )
{
	float fConstantValues[4];

	fConstantValues[0] = 50.0f / fDepthBlendScale;
	// The old depth feathering shader code worked in proj. space, which wasn't a sane place to compute depth feathering on PS3 through portals 
	// (because we use an oblique projection on PS3 to simulate user clip planes). The new methods computes depth feathering in viewspace, so 
	// we need to convert fDepthBlendScale to something which looks reasonable vs. the computing the depth blend in proj. space.
	const float flDepthFeatherFudgeFactor = 1.5f;		
	fConstantValues[1] = flDepthFeatherFudgeFactor * fDepthBlendScale;
	fConstantValues[2] = flDepthFeatherFudgeFactor / fDepthBlendScale;
	fConstantValues[3] = 0.0f;
				
	VMatrix projToViewMatrix;
	MatrixInverseGeneral( *reinterpret_cast< const VMatrix * >( &GetProjectionMatrix() ), projToViewMatrix );
	projToViewMatrix = projToViewMatrix.Transpose();

	// Send down rows 2 (Z) and 3 (W), because that's all the shader needs to recover worldspace Z.
	SetPixelShaderConstantInternal( DEPTH_FEATHER_PROJ_TO_VIEW_Z, &projToViewMatrix.m[2][0], 2 );
	// same for VS 
	SetVertexShaderConstantInternal( VERTEX_SHADER_SHADER_SPECIFIC_CONST_12, &projToViewMatrix.m[2][0], 2 );

	SetPixelShaderConstantInternal( iConstant, fConstantValues );
}