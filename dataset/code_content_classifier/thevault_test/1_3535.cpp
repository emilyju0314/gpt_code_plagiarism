IBorder *CScheme::GetBorder(const char *borderName)
{
	int symbol = KeyValuesSystem()->GetSymbolForString(borderName);
	for (int i = 0; i < m_BorderList.Count(); i++)
	{
		if (m_BorderList[i].borderSymbol == symbol)
		{
			return m_BorderList[i].border;
		}
	}

	return m_pBaseBorder;
}