FOR_EACH(it, aaReturn)
    {
        gjDataItem* pNewDataItem = new gjDataItem(*it, m_iType, m_pAPI);
        const std::string& sKey = pNewDataItem->GetKey();

        if(m_apDataItem.count(sKey))
        {
            SAFE_DELETE(pNewDataItem)
            pNewDataItem = m_apDataItem[sKey];
        }
        else m_apDataItem[sKey] = pNewDataItem;

        if(papOutput) (*papOutput)[sKey] = pNewDataItem;
    }