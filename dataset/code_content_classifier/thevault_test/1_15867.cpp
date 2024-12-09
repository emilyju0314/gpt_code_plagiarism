void
NSGenerateurFr::classeTout()
{
try
{
  reinitialise();

  // En francais, les adjectifs ayant une certitude sont toujours places apres le nom.
  //
  // Les adjectifs ont deja ete tries en avant et apres, donc on ne reverifie pas
  // qu'il s'agit bien d'adjectifs du lexique.
  //
  dispatchArray(&(pPh->adjEpitheteAv), &pAdjEpitheteAvPos, &pAdjEpitheteAvNeg);
  dispatchArray(&(pPh->adjEpitheteAp), &pAdjEpitheteApPos, &pAdjEpitheteApNeg);

  dispatchArray(&(pPh->compNom), &pCompNomPos, &pCompNomNeg, isNoun);

  dispatchArray(&(pPh->adverbe), &pAdverbePos, &pAdverbeNeg, isAdverb);

  dispatchArray(&(pPh->COD), &pCODPos, &pCODNeg, isNoun);

  dispatchArray(&(pPh->AttSujet), &pAttSujetPos, &pAttSujetNeg);
  dispatchArray(&(pPh->AttCOD), &pAttCODPos, &pAttCODNeg);

  pCCArray->classeTout();
}
catch (...)
{
	error("Exception NSGenerateurFr::classeTout", standardError);
}
}