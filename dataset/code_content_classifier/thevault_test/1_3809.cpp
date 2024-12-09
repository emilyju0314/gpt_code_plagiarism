const char *GetUserIDString( const USERID_t& id )
{
	static char idstr[ MAX_NETWORKID_LENGTH ];

	idstr[ 0 ] = 0;

	switch ( id.idtype )
	{
	case IDTYPE_STEAM:
		{
			TSteamGlobalUserID nullID;
			Q_memset( &nullID, 0, sizeof( TSteamGlobalUserID ) );

			if ( Steam3Server().BLanOnly() && !Q_memcmp( &id.uid.steamid, &nullID, sizeof( TSteamGlobalUserID ) ) ) 
			{
				strcpy( idstr, "STEAM_ID_LAN" );
			}
			else if ( !Q_memcmp( &id.uid.steamid, &nullID, sizeof( TSteamGlobalUserID ) ))
			{
				strcpy( idstr, "STEAM_ID_PENDING" );
			}
			else
			{			
				Q_snprintf( idstr, sizeof( idstr ) - 1, "STEAM_%u:%u:%u", (SteamInstanceID_t)id.uid.steamid.m_SteamInstanceID, 
													(unsigned int)((SteamLocalUserID_t)id.uid.steamid.m_SteamLocalUserID.Split.High32bits), 
													(unsigned int)((SteamLocalUserID_t)id.uid.steamid.m_SteamLocalUserID.Split.Low32bits ));			
				idstr[ sizeof( idstr ) - 1 ] = '\0';
			}
		}
		break;		
	case IDTYPE_HLTV:
		{
			strcpy( idstr, "HLTV" );
		}
		break;
	case IDTYPE_REPLAY:
		{
			strcpy( idstr, "REPLAY" );
		}
		break;
	default:
		{
			strcpy( idstr, "UNKNOWN" );
		}
		break;
	}

	return idstr;
}