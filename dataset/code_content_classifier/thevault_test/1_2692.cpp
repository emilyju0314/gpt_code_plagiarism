FOR_EACH(et, m_apScore)
        {
            gjScore* pOldScore = (*et);

            if(pOldScore->GetUserName() == pNewScore->GetUserName() &&
               pOldScore->GetSort()     == pNewScore->GetSort())
            {
                // specific score entry already available
                SAFE_DELETE(pNewScore)
                pNewScore = pOldScore;
                bNew = false;
                break;
            }
        }