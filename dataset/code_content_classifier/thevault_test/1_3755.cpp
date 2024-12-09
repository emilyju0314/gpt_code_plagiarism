bool CSystem::CommandLineParamExists(const char *paramName)
{
	if ( Q_strstr( Plat_GetCommandLine(), paramName ) )
		return true;
	
	return false;
}