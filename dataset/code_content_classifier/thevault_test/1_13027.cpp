void
SampleManager::selectSample( smp::Sample *sample )
{
	m_selectedSample = sample;

	for ( SampleUserSet::const_iterator it = m_sampleUsers.begin(); it != m_sampleUsers.end(); ++it )
		(*it)->onSelectSample( sample );
}