void CShaderAPIDx8::CompileAmbientCube( CompiledLightingState_t *pCompiledState, int nLightCount, const MaterialLightingState_t *pLightingState )
{
	Vector4D *vecCube = pCompiledState->m_AmbientLightCube;
	const Vector *pAmbient = pLightingState->m_vecAmbientCube;
	vecCube[0].Init( pAmbient[0].x, pAmbient[0].y, pAmbient[0].z, 1.0f );
	vecCube[1].Init( pAmbient[1].x, pAmbient[1].y, pAmbient[1].z, 1.0f );
	vecCube[2].Init( pAmbient[2].x, pAmbient[2].y, pAmbient[2].z, 1.0f );
	vecCube[3].Init( pAmbient[3].x, pAmbient[3].y, pAmbient[3].z, 1.0f );
	vecCube[4].Init( pAmbient[4].x, pAmbient[4].y, pAmbient[4].z, 1.0f );
	vecCube[5].Init( pAmbient[5].x, pAmbient[5].y, pAmbient[5].z, 1.0f );
}