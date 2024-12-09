bool CEconItemSchema::BInitAttributeControlledParticleSystems( KeyValues *pKVParticleSystems, CUtlVector<CUtlString> *pVecErrors )
{
	m_mapAttributeControlledParticleSystems.Purge();
	if ( NULL != pKVParticleSystems )
	{
		FOR_EACH_TRUE_SUBKEY( pKVParticleSystems, pKVEntry )
		{
			int32 nItemIndex = atoi( pKVEntry->GetName() );
			// Check to make sure the index is positive
			SCHEMA_INIT_CHECK( 
				nItemIndex > 0,
				CFmtStr( "Particle system index %d greater than zero", nItemIndex ) );
			if ( nItemIndex <= 0 )
				continue;
			int iIndex = m_mapAttributeControlledParticleSystems.Insert( nItemIndex );
			attachedparticlesystem_t *system = &m_mapAttributeControlledParticleSystems[iIndex];
			*system = GetAttachedParticleSystemInfo( pKVEntry, nItemIndex );
		}
	}
	return SCHEMA_INIT_SUCCESS();
}