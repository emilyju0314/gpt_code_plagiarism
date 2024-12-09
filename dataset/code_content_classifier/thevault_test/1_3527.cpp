HScheme CSchemeManager::GetScheme(const char *tag)
{
	for (int i=1;i<m_Schemes.Count();i++)
	{
		if ( !stricmp(tag,m_Schemes[i]->GetName()) )
		{
			return i;
		}
	}
	return 1; // default scheme
}