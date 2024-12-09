static const MaterialLightingState_t *CanonicalizeMaterialLightingStateForCSM( const MaterialLightingState_t *pOrigLightingState, MaterialLightingState_t &newLightingState, bool bStaticLight )
{
	if ( !r_force_first_dynamic_light_to_directional_for_csm.GetBool() || bStaticLight )
		return pOrigLightingState;

	// Nothing to do if there are no local lights (the shader will be adding in no light at all, so the occlusion term can't affect anything.)
	if ( ( !pOrigLightingState->m_nLocalLightCount ) || ( !g_pHardwareConfig->SupportsCascadedShadowMapping() ) )
		return pOrigLightingState;

	// Also nothing to do if there's >= 1 light, and the first light is a directional light.
	if ( ( pOrigLightingState->m_nLocalLightCount >= 1 ) && ( pOrigLightingState->m_pLocalLightDesc[0].m_Type == MATERIAL_LIGHT_DIRECTIONAL ) )
		return pOrigLightingState;
	
	// Attempt to find a directional light in the list.
	int nDirectionalLightIndex = -1;
	for ( int i = 0; i < pOrigLightingState->m_nLocalLightCount; ++i)
	{
		if ( pOrigLightingState->m_pLocalLightDesc[i].m_Type == MATERIAL_LIGHT_DIRECTIONAL )
		{
			nDirectionalLightIndex = i;
			break;
		}
	}
	
	// Create the new material lighting state.
	V_memcpy( &newLightingState, pOrigLightingState, sizeof( MaterialLightingState_t ) - MATERIAL_MAX_LIGHT_COUNT * sizeof( LightDesc_t ) );
	V_memset( &newLightingState.m_pLocalLightDesc, 0, sizeof( newLightingState.m_pLocalLightDesc ) );
		
	if ( nDirectionalLightIndex == -1 )
	{
		// Couldn't find a directional light, so make an all-black dummy one in the first slot.
		newLightingState.m_pLocalLightDesc[0].InitDirectional( Vector( 0, 0, -1 ), Vector( 0, 0, 0 ) );
	}
	else
	{
		// Force the first slot to contain the directional light.
		newLightingState.m_pLocalLightDesc[0] = pOrigLightingState->m_pLocalLightDesc[nDirectionalLightIndex];
	}

	// Now copy as many local lights as possible into the new material lighting state.
	int nSrcLightIndex = 0;
	int nDestLightIndex = 1;
	while ( ( nSrcLightIndex < pOrigLightingState->m_nLocalLightCount ) && ( nDestLightIndex < MATERIAL_MAX_LIGHT_COUNT ) )
	{
		// Don't copy the light if its the directional light found and copied earlier.
		if ( nSrcLightIndex != nDirectionalLightIndex )
		{
			newLightingState.m_pLocalLightDesc[nDestLightIndex] = pOrigLightingState->m_pLocalLightDesc[nSrcLightIndex];
			nDestLightIndex++;
		}
		
		nSrcLightIndex++;
	}

	// Set the # of local lights in the new material lighting state.
	newLightingState.m_nLocalLightCount = nDestLightIndex;

	return &newLightingState;
}