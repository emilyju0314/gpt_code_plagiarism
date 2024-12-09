bool CMaterialSystem::UpdateConfig( bool forceUpdate )
{
	int nUpdateFlags = 0;
	if ( g_pCVar && g_pCVar->HasQueuedMaterialThreadConVarSets() )
	{
		ForceSingleThreaded();
		nUpdateFlags = g_pCVar->ProcessQueuedMaterialThreadConVarSets();
	}

	MaterialSystem_Config_t config = g_config;
#ifndef DEDICATED
	ReadConfigFromConVars( &config );
#endif
	return OverrideConfig( config, forceUpdate );
}