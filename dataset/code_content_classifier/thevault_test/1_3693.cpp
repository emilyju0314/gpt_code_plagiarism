FOR_EACH_MAP( m_mapSoundMaterials, i )
	{
		nIndex--;
		if ( nIndex < 0 )
		{
			return m_mapSoundMaterials[i].GetID();
		}
	}