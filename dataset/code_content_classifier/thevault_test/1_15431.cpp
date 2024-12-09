bool NameValueParser::WriteConfigurationData( const string& aFilename )
{
  std::ofstream outStream;
  time_t rawtime;
  struct tm * timeinfo;


  outStream.open( aFilename.c_str() );
  if( !outStream.is_open() ) 
  {
		// Open failed.
		throw GOGOC_UIS__NMP_OPENFAILWRITE;
  }

  // ---------------------------------------------------------
  // Format current time for timestamp in configuration file.
  // ---------------------------------------------------------
  pal_time( &rawtime );
  timeinfo = pal_localtime( &rawtime );


  // ------------------------------
  // Write the configuration data.
  // ------------------------------
  if( m_eReadMode == NVP_READ_ALL )
  {
    t_fullFileData::iterator iter;
    t_nameValueData::iterator iterMap;

    for( iter = m_FullFileData.begin(); iter != m_FullFileData.end(); iter++ )
    {
      // Verify what kind of data:
      switch( iter->first )
      {
        case NVP_DATA_NV:
          iterMap = m_NameValue.find( iter->second );
          if( iterMap != m_NameValue.end() )
            outStream << iter->second << NV_SEPARATOR << iterMap->second << endl;
          break;
        
        case NVP_DATA_COMMENT:
          if( strncmp( iter->second.c_str(), NV_COMMENT_GENERATE, strlen(NV_COMMENT_GENERATE) ) == 0 )
          {
            outStream << NV_COMMENT_GENERATE << 
                          (timeinfo->tm_year+1900) << "/" <<
                          (timeinfo->tm_mon+1) << "/" <<
                          timeinfo->tm_mday << " " <<
                          timeinfo->tm_hour << ":" <<
                          timeinfo->tm_min << ":" <<
                          timeinfo->tm_sec << endl;
          }
          else
            outStream << iter->second << endl;
          break;
        
        case NVP_DATA_EMPTYLINE:
          outStream << endl;
          break;
      }
    }
  }
  else
  {
    t_nameValueData::iterator iter;

    for(iter = m_NameValue.begin(); iter != m_NameValue.end(); iter++ )
      outStream << iter->first << NV_SEPARATOR << iter->second << endl << endl;  
  }

  // Close opened handle.
  outStream.close();

  return true;
}