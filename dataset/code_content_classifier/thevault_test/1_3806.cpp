const char *CSourceAppSystemGroup::DetermineDefaultMod()
{
	if ( !m_bEditMode )
	{   		 
		return CommandLine()->ParmValue( "-game", DEFAULT_HL2_GAMEDIR );
	}
	return g_pHammer->GetDefaultMod();
}