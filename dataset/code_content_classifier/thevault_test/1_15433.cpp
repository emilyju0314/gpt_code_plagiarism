bool Config::ApplyConfiguration( void )
{
  assert( m_pParser != NULL );    // Need to have a parser!
  
  // If access mode is READ only, we're not suposed to write any existing 
  // configuration data.
  if( m_eAccessMode == AM_READ )
  {
    throw GOGOC_UIS__CFG_CANNOTAPPLYWHENREAD;
  }

  // Apply the changes to disk.
  return m_pParser->WriteConfigurationData( m_sConfigFile );  
}