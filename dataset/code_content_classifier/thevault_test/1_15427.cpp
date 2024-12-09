bool HACCESSDeviceMappingConfig::GetDeviceList( t_stringmap& aDeviceMap ) const
{
  stringlist nameList;
  stringlist::const_iterator iter;
  string sValue;

  m_pConfig->GetVariableNameList( nameList );

  for( iter=nameList.begin(); iter != nameList.end() ; iter++ )
  {
    m_pConfig->GetVariableValue( *iter, sValue );
    aDeviceMap[ *iter ] = sValue;
  }

  return true;
}