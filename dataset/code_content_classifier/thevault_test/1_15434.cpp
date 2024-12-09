bool Config::CancelConfiguration( void )
{
  assert( m_pParser != NULL );    // Need to have a parser!

  // If access mode is READ only, we're not suposed to be cancelling changes.
  if( m_eAccessMode == AM_READ )
  {
    throw GOGOC_UIS__CFG_CANNOTCANCELWHENREAD;
  }

  // Cancelling changes is the same as re-loading configuration data.
  return LoadConfiguration();
}