bool
NSEpiFlechiesDB::getAllLabelsForCode(string sCode, VectString *pLabels)
{
  if ((string("") == sCode) || (NULL == pLabels))
    return false;

  size_t iCodeSize = strlen(sCode.c_str());
  if (iCodeSize > FLECHIES_CODE_LEN)
    return false;

  bool bExplore = true;

#ifndef _ENTERPRISE_DLL

  NSFlechies dbFlechies(pContexte->getSuperviseur());

  HWND hParentForMessages = 0;
  if (NULL != pContexte->GetMainWindow())
    hParentForMessages = pContexte->GetMainWindow()->GetHandle();

	dbFlechies.lastError = dbFlechies.open();
	if (DBIERR_NONE != dbFlechies.lastError)
	{
        error("flechies.db -- Erreur à l'ouverture du fichier flechies.db", standardError, dbFlechies.lastError, hParentForMessages);
		return false;
	}

  dbFlechies.lastError = dbFlechies.chercheClef(&sCode, "CODES", NODEFAULTINDEX, keySEARCHGEQ, dbiREADLOCK);
	if ((DBIERR_NONE != dbFlechies.lastError) && (DBIERR_RECNOTFOUND != dbFlechies.lastError))
	{
        error("flechies.db -- erreur à la recherche dans la base flechies.db.", standardError, dbFlechies.lastError, hParentForMessages);
		dbFlechies.close();
		return false;
	}

	if (DBIERR_RECNOTFOUND == dbFlechies.lastError)
	{
		dbFlechies.lastError = dbFlechies.close();
		if (DBIERR_NONE != dbFlechies.lastError)
            error("flechies.db -- Erreur de fermeture de la base flechies.db.", standardError, dbFlechies.lastError, hParentForMessages);
		return true;
	}

  // Go from record to record while the code is good
  //
  while ((DBIERR_NONE == dbFlechies.lastError) && (true == bExplore))
  {
	  dbFlechies.lastError = dbFlechies.getRecord();
    if (dbFlechies.lastError != DBIERR_NONE)
	  {
          error("flechies.db -- erreur à la récupération de l'enregistrement", standardError, dbFlechies.lastError, hParentForMessages);
      bExplore = false;
		  break;
	  }

    // Check that sRecordCode includes sCode as a begining
    //
    string sRecordCode = dbFlechies.getCode();
    if (strlen(sRecordCode.c_str()) < iCodeSize)
      break;
    if (string(sRecordCode, 0, iCodeSize) != sCode)
      break;

    pLabels->push_back(new string(dbFlechies.getLabel()));

    dbFlechies.lastError = dbFlechies.suivant(dbiREADLOCK);
    if (dbFlechies.lastError != DBIERR_NONE)
    {
      if (dbFlechies.lastError != DBIERR_EOF)
      {
        error("flechies.db -- erreur au passage à l'enregistrement suivant", standardError, dbFlechies.lastError, hParentForMessages);
        bExplore = false;
      }
    }
  }

  dbFlechies.lastError = dbFlechies.close();
	if (dbFlechies.lastError != DBIERR_NONE)
        error("flechies.db -- Erreur de fermeture de la base flechies.db.", standardError, dbFlechies.lastError, hParentForMessages);

#else

  // Looking for all codes that belong to given classification
  //
  string sQuery = string("SELECT * FROM flechies WHERE CODE = \"") + sCode + string("\"");

  ontologyBaseManager* pOntologyManager = pContexte->getSuperviseur()->getDatabaseManager();
  if (NULL == pOntologyManager)
    return false;

  MYSQL_RES *pResult = pOntologyManager->executeQuery(sQuery, false);
  if ((MYSQL_RES *) NULL == pResult)
    return false;

  MYSQL_ROW Row = mysql_fetch_row(pResult);
  while (Row)
  {
    NSFlechiesInfo flechiesInfo;
    flechiesInfo.alimenteFiche(&Row);

    pLabels->push_back(new string(flechiesInfo.getLabel()));

    Row = mysql_fetch_row(pResult);
  }

  mysql_free_result(pResult);

#endif

  return bExplore;
}