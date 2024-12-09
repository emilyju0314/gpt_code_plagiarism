bool Config::LoadConfiguration( void )
{
  assert( m_pParser != NULL );    // Need to have a parser!
  
  // If access mode is CREATE, we're not suposed to load any existing 
  // configuration.
  if( m_eAccessMode == AM_CREATE )
  {
    throw GOGOC_UIS__CFG_CANNOTLOADWHENCREATE;
  }
  
  // Read configuration.
  // May throw exception if file doesn't exist.
  return m_pParser->ReadConfigurationData( m_sConfigFile );
}