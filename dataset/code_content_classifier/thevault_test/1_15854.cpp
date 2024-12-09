void
NSGenerateur::dispatchArray(NSPhraseMotArray* pMots, NSPhraseMotArray** ppYesArray, NSPhraseMotArray** ppNoArray, WORDTYPE iWordType)
{
  if (NULL == pMots)
    return;

  if (pMots->empty())
    return;

  for (iterPhraseMot iterMots = pMots->begin(); pMots->end() != iterMots; iterMots++)
  {
    bool bFound = true;

    if (false == (*iterMots)->estTexteLibre())
    {
      NSSuper* pSuper = pContexte->getSuperviseur();

      string sLexique = (*iterMots)->getLexique();

      NSPathologData Data;
      bFound = pContexte->getDico()->trouvePathologData(sLang, &sLexique, &Data);
      if (false == bFound)
      {
        string sErrorText = string("NSGenerateur::dispatchArray discarding ") + sLexique + string(" which cannot be found in Lexique for langage ") + sLang;
        pSuper->trace(&sErrorText, 1, NSSuper::trWarning);
      }
      else
      {
        switch(iWordType)
        {
          case isNoun :
          {
            if (false == Data.estNom())
            {
              string sErrorText = string("NSGenerateurFr::classeTout discarding ") + sLexique + string(" because it is no a noun.");
              pSuper->trace(&sErrorText, 1, NSSuper::trWarning);
              bFound = false;
            }
            break;
          }
          case isAdjective :
          {
            if (false == Data.estAdjectif())
            {
              string sErrorText = string("NSGenerateurFr::classeTout discarding ") + sLexique + string(" because it is not an adjective.");
              pSuper->trace(&sErrorText, 1, NSSuper::trWarning);
              bFound = false;
            }
            break;
          }
          case isAdverb :
          {
            if (false == Data.estAdverbe())
            {
              string sErrorText = string("NSGenerateurFr::classeTout discarding ") + sLexique + string(" because it is not an adverb.");
              pSuper->trace(&sErrorText, 1, NSSuper::trWarning);
              bFound = false;
            }
            break;
          }
          case isVerb :
          {
            if (false == Data.estVerbe())
            {
              string sErrorText = string("NSGenerateurFr::classeTout discarding ") + sLexique + string(" because it is not a verb.");
              pSuper->trace(&sErrorText, 1, NSSuper::trWarning);
              bFound = false;
            }
            break;
          }
          case isInvar :
          {
            if (false == Data.estInvariable())
            {
              string sErrorText = string("NSGenerateurFr::classeTout discarding ") + sLexique + string(" because it is not an invariable.");
              pSuper->trace(&sErrorText, 1, NSSuper::trWarning);
              bFound = false;
            }
            break;
          }
        }
      }
    }

    if (bFound)
      dispatchYesNo(*iterMots, ppYesArray, ppNoArray);
  }
}