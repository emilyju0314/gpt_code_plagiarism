FOR_EACH(it, m_apVerify)
    {
        if((*it) == pNewScore)
        {
            m_apVerify.erase(it);
            break;
        }
    }