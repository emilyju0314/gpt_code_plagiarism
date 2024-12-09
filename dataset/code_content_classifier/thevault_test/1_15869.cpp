string
NSGenerateurFr::donnePhraseComplement(NSPhraseMot* pLiaison,
                                      NSPhraseMot* pPreposition,
                                      NSPhraseMotArray* pCC,
                                      bool* bSucces)
{
  *bSucces = false;

  string sInter1 = "";
  string sInter2 = "";
  string sPhr = "";

  bool     trouve;
  NSSuper* pSuper = pContexte->getSuperviseur();
  string   sLexique;
  string   sPluriel;
  GENRE    iGenre;

  iterPhraseMot  iterMots;
  NSPathologData Data;

  if (false == pCC->empty())
  {
    for (iterMots = pCC->begin(); iterMots != pCC->end(); iterMots++)
    {
      sInter2 = "";

      // Est-ce une donnée chiffrée ?
      string sFormat = (*iterMots)->getFormat();

      // Est-ce une structure de type NSPhraseMotTime ?
      // Is it a NSPhraseMotTime object
      NSPhraseMotTime* pDate = dynamic_cast<NSPhraseMotTime*>(*iterMots);
      if ( pDate )
      {
        bool bSucces;
        string sTimeLibel = decodeTime(pDate, &bSucces);
        if (bSucces)
          sInter2 = sTimeLibel;
      }
      else
      {
        NSPhraseMotTimeCycle* pCycle = dynamic_cast<NSPhraseMotTimeCycle*>(*iterMots);
        if ( pCycle )
        {
          bool bSucces;
          string sCycleLibel = decodeCycle(pCycle, &bSucces);
          if (bSucces)
            sInter2 = sCycleLibel;
        }
        //
        // Ni valeur chiffrée, ni date
        // Not a number, nor a date
        //
        else if (string("") == sFormat)
        {
          sLexique = (*iterMots)->getLexique();
          sPluriel = (*iterMots)->getPluriel();

          if (false == (*iterMots)->estTexteLibre())
          {
            trouve = pContexte->getDico()->trouvePathologData(sLang, &sLexique, &Data);
            if (!trouve)
              return "";
            if (!(Data.estNom()))
              return "";

            // L'article du statut d'objet reel ou abstrait

            if ((*iterMots)->getArticle() != NSPhraseMot::articleSans)
            {
              if (sPluriel == "")
                sInter2 = donneNomComplet(*iterMots, (*iterMots)->getArticle(), sansCertitude);
              else if (string(sPluriel, 0, 5) == "WPLUR")
                sInter2 = donneNomComplet(*iterMots, NSPhraseMot::articleDefini, sansCertitude);
              else if (string(sPluriel, 0, 5) == "WPLUS")
                sInter2 = donneNomComplet(*iterMots, NSPhraseMot::articleIndefini, sansCertitude);
            }
            else
              sInter2 = donneNomComplet(*iterMots, NSPhraseMot::articleSans, sansCertitude);

            string sCertitude = string((*iterMots)->getCertitude(), 0, 5);
            string sCertitudeEcrit = donneCertitude(sCertitude);

            if (sCertitudeEcrit != "")
              sInter2 = sCertitudeEcrit + string(" ") + sInter2;
          }
          else
            sInter2 = (*iterMots)->getTexteLibre();
        }
        else
        {
          //
          // Date "simple"
          // "Simple" date
          //
          if      ((sFormat[0] == '£') &&
                       ((sFormat[1] == dateMARK) || (sFormat[1] == dateHeureMARK)))
          {
            string sComplement = (*iterMots)->getComplement();
            string sUnite      = (*iterMots)->getUnite();

            gereDateFr Date(pContexte->getSuperviseur(), sLang);
            Date.setDate(&sComplement);
            Date.setFormat(&sFormat);

            string sUniteSens = "";
            pContexte->getDico()->donneCodeSens(&sUnite, &sUniteSens);
            Date.setUnite(&sUniteSens);

            string sLibel, sIntro;

            Date.donne_date_claire(&sLibel, &sIntro);
            sInter2 = sIntro + sLibel;
          }
        }
      }
      etDuMilieu(&sPhr, &sInter1, &sInter2);
    }
    etFinal(&sPhr, &sInter1);

    // Traitement de la préposition globale
    sLexique = pPreposition->getLexique();
    if (string("") != sLexique)
    {
      sPluriel = pPreposition->getPluriel();
      trouve = pContexte->getDico()->trouvePathologData(sLang, &sLexique, &Data);
      if (false == trouve)
        return string("");
      Data.donneGenre(&iGenre);
      if (sPluriel != "")
        Data.donneGenrePluriel(&iGenre);
      donneLibelleAffiche(&sInter2, &Data, iGenre);
      sPhr = sInter2 + " " + sPhr;
    }
    // Traitement de l'élément de liaison
    sLexique = pLiaison->getLexique();
    if (string("") != sLexique)
    {
      sPluriel = pLiaison->getPluriel();
      trouve = pContexte->getDico()->trouvePathologData(sLang, &sLexique, &Data);
      if (false == trouve)
        return string("");
      if (Data.estVerbe())
      {
        sInter2 = donneParticipePresent(&Data);
        sPhr = sInter2 + " " + sPhr;
      }
      else
      {
        Data.donneGenre(&iGenre);
        if (sPluriel != "")
          Data.donneGenrePluriel(&iGenre);
        donneLibelleAffiche(&sInter2, &Data, iGenre);
        sPhr = sInter2 + " " + sPhr;
      }
    }
  }
  *bSucces = true;
  return sPhr;
}