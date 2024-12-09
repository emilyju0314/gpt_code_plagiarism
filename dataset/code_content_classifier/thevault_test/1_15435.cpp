bool Config::OverrideConfiguration( const string& aFileName )
{
  assert( m_pParser != NULL );
  
  // Check if we're overriding with the same data from the same file.
  if( aFileName == m_sConfigFile )
  {
    throw GOGOC_UIS__CFG_CANNOTOVERRIDESAMECONTENTS;
  }

  // If access mode is READ only, we're not suposed to be overriding 
  // configuration data.
  if( m_eAccessMode == AM_READ )
  {
    throw GOGOC_UIS__CFG_CANNOTOVERRIDEWHENREAD;
  }

  // Override the configuration data with the one from the specified file.
  // and apply the configuration to the config file.
  return m_pParser->ReadConfigurationData( aFileName ) &&
         m_pParser->WriteConfigurationData( m_sConfigFile );  
}