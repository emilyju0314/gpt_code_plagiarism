bool HACCESSDeviceMappingConfig::CancelChanges( void )
{
  assert( m_pConfig != NULL );

  return m_pConfig->CancelConfiguration();
}