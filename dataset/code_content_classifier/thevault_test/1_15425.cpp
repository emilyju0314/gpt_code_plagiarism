bool HACCESSDeviceMappingConfig::SetDeviceAddress( const string& aName, const string& aAddress )
{
  assert( m_pConfig != NULL );

  m_pConfig->SetVariableValue( aName, aAddress );

  return true;
}