bool
NSDico::Prend()
{
#ifndef _ENTERPRISE_DLL
	// Lexique général - All purposes lexicon
	//
	if ((_bOuvreFerme) && (NULL == _pPatho))
	{
        _pPatho = new NSPatholog(pContexte->getSuperviseur(), _sUserLang);
		//
		// Ouverture du fichier
		//
        _pPatho->lastError = _pPatho->open();
		if (DBIERR_NONE != _pPatho->lastError)
		{
        string sErrorText = pContexte->getSuperviseur()->getText("lexiqueErrors", "errorOpeningLexique");
      sErrorText += string(" (") + _sUserLang + string(")");
      pContexte->getSuperviseur()->trace(&sErrorText, 1, NSSuper::trError);
            error(sErrorText.c_str(), standardError, _pPatho->lastError);

            delete _pPatho;
      _pPatho = (NSPatholog*) 0;

            return false;
		}
	}

  // Médicaments - Drugs lexicon
  //
  if ((_bOuvreFerme) && (NULL == _pLexiMed))
  {
    _pLexiMed = new NSLexiMed(pContexte->getSuperviseur(), _sUserLang);
		//
		// Ouverture du fichier
		//
        _pLexiMed->lastError = _pLexiMed->open();
		if (DBIERR_NONE != _pLexiMed->lastError)
		{
            string sErrorText = pContexte->getSuperviseur()->getText("lexiqueErrors", "errorOpeningDrugsLexique");
      sErrorText += string(" (") + _sUserLang + string(")");
      pContexte->getSuperviseur()->trace(&sErrorText, 1, NSSuper::trError);
            error(sErrorText.c_str(), standardError, _pPatho->lastError);

            delete _pLexiMed;
      _pLexiMed = (NSLexiMed*) 0;

            return false;
    }
	}
#else

  _pPatho   = new NSPatholog(pContexte->getSuperviseur(), _sUserLang);
  _pLexiMed = new NSLexiMed(pContexte->getSuperviseur(), _sUserLang);

#endif

	// Générateur - Langage generator
	//
	if ("en" == _sUserLang)
        _pGenerateur = new NSGenerateurEn(pContexte, _pProposition, string("en"));
  else
    _pGenerateur = new NSGenerateurFr(pContexte, _pProposition, string("fr"));

    return true;
}