FOR_EACH_VEC( m_InputItemsCriteria, nCriteria )
		{
			if ( pDupesUsed[ nCriteria ] < m_InputItemDupeCounts[ nCriteria ] )
			{
				// Not all criteria dupes were matched
				bResult = false;
				break;
			}
		}