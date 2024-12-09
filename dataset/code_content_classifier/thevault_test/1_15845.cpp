void
NSDico::donneCodeSens(string* pCodeLexique, string* pCodeSens)
{
	if (NULL == pCodeSens)
    return;

  *pCodeSens = string("");

  if ((NULL == pCodeLexique) || (string("") == *pCodeLexique))
    return;

  string sBuffer = string("");

  // Chercher la position de cheminSeparationMARK dans la chaine
  size_t positChem = pCodeLexique->find(string(1, cheminSeparationMARK));
  // Chercher la position de nodeSeparationMARK dans la chaine
  size_t positNode = pCodeLexique->find(string(1, nodeSeparationMARK));
  // Chercher la position de intranodeSeparationMARK dans la chaine
  size_t positINod = pCodeLexique->find(string(1, intranodeSeparationMARK));

  if ((string::npos == positNode) && (string::npos == positChem) && (string::npos == positINod))
  {
    sBuffer = *pCodeLexique;
    donneCodeSens(sBuffer);
    *pCodeSens = sBuffer;
    return;
	}

  size_t posit = min(positChem, positNode);
  posit = min(posit, positINod);
  size_t debut = 0;

  char cSepare;

	while (((string::npos != positNode) || (string::npos != positChem) || (string::npos != positINod)) &&
                                    (posit < strlen(pCodeLexique->c_str())))
  {
    cSepare = (*pCodeLexique)[posit];

    sBuffer = string(*pCodeLexique, debut, posit - debut);
    donneCodeSens(sBuffer);
    *pCodeSens = *pCodeSens + sBuffer + string(1, cSepare);

    debut = posit + 1;
    positChem = pCodeLexique->find(string(1, cheminSeparationMARK), debut);
    positNode = pCodeLexique->find(string(1, nodeSeparationMARK), debut);
    positINod = pCodeLexique->find(string(1, intranodeSeparationMARK), debut);

    posit = min(positChem, positNode);
    posit = min(posit, positINod);
  }

    sBuffer = string(*pCodeLexique, debut, strlen(pCodeLexique->c_str()) - debut);
  donneCodeSens(sBuffer);
  *pCodeSens = *pCodeSens + sBuffer;
}