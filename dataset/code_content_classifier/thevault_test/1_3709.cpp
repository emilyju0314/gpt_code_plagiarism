void CMaterialSystem::GetDisplayMode( MaterialVideoMode_t& info ) const
{
	ShaderDisplayMode_t shaderInfo;
	g_pShaderDeviceMgr->GetCurrentModeInfo( &shaderInfo, m_nAdapter );
	ConvertModeStruct( &info, shaderInfo );
}