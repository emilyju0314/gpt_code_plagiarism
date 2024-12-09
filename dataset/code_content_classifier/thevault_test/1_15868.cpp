string
NSGenerateurFr::donneAdverbeComplet(NSPhraseMot* pMot, GERECERTITUDE iGereCertitude)
{
  string sLibel = string("");
  NSPathologData Data;

  string sCertitude;

  string sLexique = pMot->getLexique();

  bool trouve = pContexte->getDico()->trouvePathologData(sLang, &sLexique, &Data);
  if (false == trouve)
    return string("");
  if (false == Data.estAdverbe())
    return string("");

  donneLibelleAffiche(&sLibel, &Data);

  if (pMot->getComplementPhr())
  {
    NsProposition Propos(pContexte, pMot->getComplementPhr(), NsProposition::notSetType, NsProposition::notSetConjonct);
    NSGenerateurFr GeneCpl(pContexte, &Propos, sLang);
    if (GeneCpl.genereAdverbeComplet(pMot, iGereCertitude))
      sLibel = GeneCpl.getTempoPhrase();
  }

  if (iGereCertitude == avecCertitude)
  {
    sCertitude = string(pMot->getCertitude(), 0, 5);
    string sCertitudeEcrit = donneCertitude(sCertitude);

    if (sCertitudeEcrit != "")
      sLibel = sCertitudeEcrit + string(" ") + sLibel;
  }

  return sLibel;
}