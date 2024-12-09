void CSchemeManager::ReloadSchemes()
{
	int count = m_Schemes.Count();
	Shutdown( false );
	
	// reload the scheme
	for (int i = 1; i < count; i++)
	{
		LoadSchemeFromFile(m_Schemes[i]->GetFileName(), m_Schemes[i]->GetName());
	}
}