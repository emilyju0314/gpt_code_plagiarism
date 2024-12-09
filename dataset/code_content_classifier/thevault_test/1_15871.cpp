bool
NSGenerateurFr::traitePostposition(NSPhraseMot* pMot, NSPhraseMotArray* pSpecifique)
{
    NSSuper* pSuper = pContexte->getSuperviseur();
    iterPhraseMot  iterMots;
    NSPathologData Data;
    bool trouve;
    string sLexique = pMot->getLexique();
    string sPostposition = "";

    trouve = pContexte->getDico()->trouvePathologData(sLang, &sLexique, &Data);
    if (!trouve)
        return false;

    string sPostpositionBrute = Data.chercheGrammaire(POSTPOSITION);
    if (sPostpositionBrute == "")
        return false;

    // La postposition est la string sPostpositionBrute privee du "O" initial.

    sPostposition = string(sPostpositionBrute, 1, strlen(sPostposition.c_str()) - 1);

    // Si pMot est un nom, il peut imposer une preposition a son complement du nom.

    if (pMot->getComplementPhr())
    {
        NSPhraseur* pComp = pMot->getComplementPhr();

        if (!(pComp->compNom.empty()))
        {
            for (iterMots = pComp->compNom.begin(); iterMots != pComp->compNom.end(); iterMots++)
            {
                if (!((*iterMots)->estTexteLibre()))
                    (*iterMots)->setPreposition(sPostposition);
                else
                {
                    // On rajoute la preposition dans le libelle du texte libre.
                    (*iterMots)->setPreposition(sPostposition);
                    (*iterMots)->setTexteLibre(sPostposition + string(" ")
                                                + (*iterMots)->getTexteLibre());
                }
            }
        }
    }

    // Si pMot est un verbe, il peut imposer une preposition au COI ou au COS.

    if (Data.estVerbe())
    {
        if (!(pPh->COI.empty()))
        {
            for (iterMots = pPh->COI.begin(); iterMots != pPh->COI.end(); iterMots++)
            {
                if (!((*iterMots)->estTexteLibre()))
                    (*iterMots)->setPreposition(sPostposition);

                else
                {
                    // On rajoute la preposition dans le libelle du texte libre.
                    (*iterMots)->setPreposition(sPostposition);
                    (*iterMots)->setTexteLibre(sPostposition + string(" ")
                                                + (*iterMots)->getTexteLibre());
                }
            }
        }

        if (false == pPh->COS.empty())
        {
            for (iterMots = pPh->COS.begin(); iterMots != pPh->COS.end(); iterMots++)
            {
                if (!((*iterMots)->estTexteLibre()))
                    (*iterMots)->setPreposition(sPostposition);

                else
                {
                    // On rajoute la preposition dans le libelle du texte libre.
                    (*iterMots)->setPreposition(sPostposition);
                    (*iterMots)->setTexteLibre(sPostposition + string(" ")
                                                + (*iterMots)->getTexteLibre());
                }
            }
        }
    }

    if (pSpecifique)
    {
        if (!(pSpecifique->empty()))
        {
            for (iterMots = pSpecifique->begin(); iterMots != pSpecifique->end(); iterMots++)
            {
                if (!((*iterMots)->estTexteLibre()))
                    (*iterMots)->setPreposition(sPostposition);

                else
                {
                    // On rajoute la preposition dans le libelle du texte libre.
                    (*iterMots)->setPreposition(sPostposition);
                    (*iterMots)->setTexteLibre(sPostposition + string(" ")
                                                + (*iterMots)->getTexteLibre());
                }
            }
        }
    }

    return true;
}