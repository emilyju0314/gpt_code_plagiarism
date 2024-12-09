void
NSGenerateur::dispatchYesNo(NSPhraseMot* pMot, NSPhraseMotArray** ppYesArray, NSPhraseMotArray** ppNoArray)
{
  if (NULL == pMot)
    return;

  string sCertitude = pMot->getCertitude();
  if (string("") != sCertitude)
  {
    if      ((string(sCertitude, 0, 3) == "WCE") &&
             (string(sCertitude, 0, 5) < "WCE50"))
      ajouteCopieMot(ppNoArray, pMot);

    else if ((string(sCertitude, 0, 3) == "WCE") &&
             (string(sCertitude, 0, 5) >= "WCE50"))
      ajouteCopieMot(ppYesArray, pMot);
  }
  else
    ajouteCopieMot(ppYesArray, pMot);
}