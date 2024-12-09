bool HACCESSDeviceMappingConfig::GetDeviceNameList( t_stringarray& aNameList ) const
{
  stringlist nameList;
  stringlist::const_iterator iter;

  m_pConfig->GetVariableNameList( nameList );

  for( iter=nameList.begin(); iter != nameList.end() ; iter++ )
    aNameList.push_back( *iter );

  return true;
}